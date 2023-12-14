// ros-script.js
var connected = 0;
var ros = new ROSLIB.Ros({
    url: 'ws://loic-ras.freeboxos.fr:9090'
});

ros.on('connection', function () {
    connected = 1;
    console.log('Connecté au serveur websocket ROS.');
});


ros.on('error', function (error) {
    console.log('Erreur de connexion au serveur websocket ROS: ', error);
});

ros.on('close', function () {
     //if (connected == 0) {
     //    window.location.href = 'rickroll.html';
     //}
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

function stopJoystick() {
    if (manager) {
        manager.trigger('end'); // Force l'événement 'end' quand je décharge la page
    }
}

function move() {
    publishWebMode(7, throttle, steering, reverse);
}

function createJoystick() {
    var options = {
        zone: document.getElementById('zone_joystick'),
        threshold: 0.1,
        position: { left: '50%', top: '50%' },
        mode: 'static',
        size: 100,
        color: 'grey',
    };

    var manager = nipplejs.create(options);

    manager.on('move', function (event, nipple) {
        //console.log("Moving");
        var max_throttle = 1.0;
        var max_reverse_distance = 37.5; // pixels;
        var max_steering = 1.0;

        // Calcul des valeurs
        var adjusted_max_reverse_distance = (max_reverse_distance / 150) * options.size;

        throttle = nipple.distance / (adjusted_max_reverse_distance * 2) * max_throttle;
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

    return manager;
}

window.onload = function () {
    var manager = createJoystick();
}

window.addEventListener('beforeunload', stopJoystick);

var stateListener = new ROSLIB.Topic({
    ros: ros,
    name: '/state',
    messageType: 'interfaces/msg/State',
    queue_size: 10
});

var stateData = [];

stateListener.subscribe(function (message) {
    
    stateData.push('Current State: ' + message.current_state +
        '<br>State Name: ' + message.state_name +
        '<br>Obstacle Detection: ' + message.obstacle_detect);


    switch (message.current_state) {
        case 0:
            window.location.href = 'home.html';
            break;
        case 1:
            publishWebMode(7, 0, 0, false);
            window.location.href = 'manual.html';
            break;
        case 2:
            window.location.href = 'autonomous.html';
            break;
        case 3:
            window.location.href = 'tracking.html';
            break;
        case 4:
            publishWebMode(7, 0, 0, false);
            window.location.href = 'security.html';
            break;        
        case 5:
            window.location.href = 'emergency.html';
            break;
        default:
            console.log('Unknown State');
    }
});

var generalDataListener = new ROSLIB.Topic({
    ros: ros,
    name: '/general_data', 
    messageType: 'interfaces/msg/GeneralData'
});


function updateBatteryDisplay(message) {
    if (message.battery_level !== undefined) {
        var batteryLevelDiv = document.getElementById('batteryLevel');

        batteryLevelDiv.style.width = message.battery_level + '%';
        document.getElementById('batteryText').innerText = message.battery_level + '%';
        batteryLevelDiv.classList.remove('battery-low', 'battery-medium', 'battery-normal', 'battery-high');

        if (message.battery_level <= 15) {
            batteryLevelDiv.classList.add('battery-low');
        } else if (message.battery_level <= 25) {
            batteryLevelDiv.classList.add('battery-medium');
        } else if (message.battery_level < 80) {
            batteryLevelDiv.classList.add('battery-normal');
        } else {
            batteryLevelDiv.classList.add('battery-high');
        }
    }
}

generalDataListener.subscribe(updateBatteryDisplay);


window.history.forward();