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

function selectMode(mode) {
    var modePublisher = new ROSLIB.Topic({
        ros: ros,
        name: '/web_mode',
        messageType: 'interfaces/msg/WebMode'
    });

    var modeMsg = new ROSLIB.Message({
        button: mode
    });

    modePublisher.publish(modeMsg);
    console.log('Commande envoyée: ' + mode);
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
