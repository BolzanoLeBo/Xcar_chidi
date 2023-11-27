// ros-script.js

var ros = new ROSLIB.Ros({
    url: 'ws://localhost:9090'
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
        messageType: 'std_msgs/String'
    });

    var modeMsg = new ROSLIB.Message({
        data: mode
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

    if (message.current_state) {
        alert("Object Detected!");
    }
});
