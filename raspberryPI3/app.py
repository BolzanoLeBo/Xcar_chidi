from flask import Flask, render_template, request
import rclpy
from std_msgs.msg import String

app = Flask(__name__)

# Initialiser ROS 2
rclpy.init()

# Créer un éditeur pour le topic de commande
publisher = rclpy.create_node('command_publisher').create_publisher(String, 'mode_command', 10)

@app.route('/')
def index():
    return app.send_static_file('index.html')

@app.route('/select_mode', methods=['POST'])
def select_mode():
    mode = request.form['mode']
    # Envoyer la commande au topic ROS 2
    msg = String()
    msg.data = mode
    publisher.publish(msg)
    return 'Commande envoyée'

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')