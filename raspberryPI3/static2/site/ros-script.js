var ros = new ROSLIB.Ros({
    url: 'ws://loic-ras.freeboxos.fr:80'
});

ros.on('connection', function () {
    console.log('Connecté au serveur websocket ROS.');
});


ros.on('error', function (error) {
    console.log('Erreur de connexion au serveur websocket ROS: ', error);
});

ros.on('close', function () {
     console.log('Connexion au serveur websocket ROS fermée.');
 });

var modePublisher = new ROSLIB.Topic({
    ros: ros,
    name: '/web_mode',
    messageType: 'interfaces/msg/WebMode'
});

function publishWebMode(button, throttle, steering, reverse) {
    var modeMsg = new ROSLIB.Message({
        button: button,
        throttle: throttle,
        steering: steering,
        reverse: reverse
    });

    modePublisher.publish(modeMsg);
    //console.log('Commande envoyée - Button:', button, 'Throttle:', throttle, 'Steering:', steering, 'Reverse:', reverse);
}

function selectMode(mode) {
    publishWebMode(mode, 0, 0, false);
}

var throttle = 0;
var reverse = false;
var steering = 0;
var timer;
var state = 0;

function stopJoystick() {
    if (manager) {
        manager.trigger('end'); // Force l'événement 'end' quand je décharge la page
    }
}

function move() {
    publishWebMode(7, throttle, steering, reverse);
}

var manager;

function createJoystick() {
    var options = {
        zone: document.getElementById('zone_joystick'),
        threshold: 0.1,
        position: { left: '50%', top: '50%' },
        mode: 'static',
        size: 100,
        color: 'grey',
    };

    manager = nipplejs.create(options);

    manager.on('move', function (event, nipple) {
        //console.log("Moving");
        var max_throttle = 1.0;
        var max_reverse_distance = 37.5; // pixels;
        var max_steering = 1.0;

        // Calcul des valeurs
        var adjusted_max_reverse_distance = (max_reverse_distance / 150) * options.size;

        throttle = nipple.distance / (adjusted_max_reverse_distance * 2) * max_throttle;
        throttle = throttle * Math.abs(Math.sin(nipple.angle.radian));
        steering = Math.cos(nipple.angle.radian) * max_steering;

        throttle = Math.max(0, Math.min(throttle, 1));
        steering = Math.max(-1, Math.min(steering, 1));
    });

    manager.on('plain:up', function () {
        reverse = false;
    });

    manager.on('plain:down', function () {
        reverse = true;
    });

    manager.on('start', function () {
        //console.log("Movement start");
        if (!timer) {
            timer = setInterval(move, 25);
        }
    });

    manager.on('end', function () {
        //console.log("Movement end");
        if (timer) {
            clearInterval(timer);
            timer = null;
        }
        throttle = 0;
        steering = 0;
        reverse = false;
        move();
    });
    console.log('Oui');
    return manager;
}

//window.onload = function () {
//     manager = createJoystick();
//}

window.addEventListener('beforeunload', stopJoystick);

var stateListener = new ROSLIB.Topic({
    ros: ros,
    name: '/state',
    messageType: 'interfaces/msg/State',
    queue_size: 10
});

var stateInfoDiv = document.getElementById('stateInfo');
var stateData = [];

stateListener.subscribe(function (message) {
    stateData.push('Current State: ' + message.current_state +
        '<br>State Name: ' + message.state_name +
        '<br>Obstacle Detection: ' + message.obstacle_detect);

    // Mettre à jour les informations d'état dans le DOM
    document.getElementById('stateInfo').innerHTML = stateData.join('<br><br>');

    switch (message.current_state) {
        case 0:
            state=0;
            break;
        case 1:
            state=1;
            publishWebMode(7, 0, 0, false);
            break;
        case 2:
            state=2;
            break;
        case 3:
            state=3;
            break;
        case 4:
            publishWebMode(7, 0, 0, false);
            state=4;
            break;        
        case 5:
            state=5;
            break;
        default:
            console.log('Unknown State');
    }
    showAppropriateDiv();
});

var listener = new ROSLIB.Topic({
    ros: ros,
    name: '/some_topic',
    messageType: 'std_msgs/String'
});

listener.subscribe(function (message) {
    if (message.action === 'redirect') {
        window.location.href = 'rickroll.html';
    }
});

var generalDataListener = new ROSLIB.Topic({
    ros: ros,
    name: '/general_data', 
    messageType: 'interfaces/msg/GeneralData'
});


function voltageToPercentage(voltage) {
    // Définir les valeurs minimale et maximale de la tension
    var minVoltage = 9;
    var maxVoltage = 14;

    // Assurer que la tension est dans la plage définie
    voltage = Math.max(minVoltage, Math.min(voltage, maxVoltage));

    // Effectuer la conversion linéaire
    var percentage = ((voltage - minVoltage) / (maxVoltage - minVoltage)) * 100;

    // Arrondir le pourcentage à deux décimales
    return Math.round(percentage * 100) / 100;
}

function updateBatteryDisplay(message) {
    if (message.battery_level !== undefined) {
        var batteryLevelDiv = document.getElementById('batteryLevel');

        // Convertir la tension en pourcentage
        var percentage = voltageToPercentage(message.battery_level);

        batteryLevelDiv.style.width = percentage + '%';
        document.getElementById('batteryText').innerText = percentage + '%';
        batteryLevelDiv.classList.remove('battery-low', 'battery-medium', 'battery-normal', 'battery-high');

        if (percentage <= 15) {
            batteryLevelDiv.classList.add('battery-low');
        } else if (percentage <= 25) {
            batteryLevelDiv.classList.add('battery-medium');
        } else if (percentage < 80) {
            batteryLevelDiv.classList.add('battery-normal');
        } else {
            batteryLevelDiv.classList.add('battery-high');
        }
    }
}

/*var updateTimeout;
var updateDelay = 1000; // Délai en millisecondes (1 seconde)

function updateBatteryDisplayDelayed(message) {
    // Effacer tout timeout précédent (s'il y en a)
    clearTimeout(updateTimeout);

    // Définir un nouveau timeout pour déclencher la mise à jour après le délai spécifié
    updateTimeout = setTimeout(function () {
        // Appeler la fonction de mise à jour de la batterie
        updateBatteryDisplay(message);
    }, updateDelay);
}*/

generalDataListener.subscribe(updateBatteryDisplay);

window.history.forward();