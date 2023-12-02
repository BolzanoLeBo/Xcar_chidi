// ros-script.js

var ros = new ROSLIB.Ros({
    url: 'ws://10.105.1.167:9090'
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

function move() {
    publishWebMode(7, throttle, steering, reverse);
}

function createJoystick() {
    var options = {
        zone: document.getElementById('zone_joystick'),
        threshold: 0.1,
        position: { left: '50%', top: '50%' },
        mode: 'static',
        size: 150,
        color: '#000000',
    };

    var manager = nipplejs.create(options);

    manager.on('move', function (event, nipple) {
        //console.log("Moving");
        var max_throttle = 1.0;
        var max_reverse_distance = 37.5; // pixels;
        var max_steering = 1.0;

        // Calcul des valeurs
        throttle = nipple.distance / (max_reverse_distance * 2) * max_throttle;
        steering = Math.cos(nipple.angle.radian) * max_steering;
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
}

window.onload = function () {
    createJoystick();
}

var stateListener = new ROSLIB.Topic({
    ros: ros,
    name: '/state',
    messageType: 'interfaces/msg/State'
});

stateListener.subscribe(function (message) {
    var stateData = 'Current State: ' + message.current_state +
        '<br>State Name: ' + message.state_name +
        '<br>Obstacle Detection: ' + message.obstacle_detect;

    document.getElementById('stateData').innerHTML = 'Data from "state" topic:<br>' + stateData;

    switch (message.current_state) {
        case 0:
            window.location.href = 'home.html';
            break;
        case 1:
            window.location.href = 'manual.html';
            break;
        case 2:
            window.location.href = 'autonomous.html';
            break;
        case 3:
            window.location.href = 'tracking.html';
            break;
        case 4:
            window.location.href = 'security.html';
            break;        
        case 5:
            window.location.href = 'emergency.html';
            break;
        default:
            console.log('Unknown State');
    }
});
