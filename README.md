# GeiCar Project

The GeiCar project is a project carried out by students at [INSA Toulouse](http://www.insa-toulouse.fr/fr/index.html). This project consists in developing the software of a autonomous car in order to carry out different missions. Several projects are exposed on the [official website] (https://sites.google.com/site/projetsecinsa/).

This repository is intended to provide a basis for students starting a new project on the GeiCar. The present code as well as the documentation is the result of internship carried out by [Alexis24](https://github.com/Alexix24) (Alexis Pierre Dit Lambert)

The platform is developped and maintained by :

* DI MERCURIO Sébastien
* LOMBARD Emmanuel
* MARTIN José

The projects are (or were) surpervised by:

* CHANTHERY Elodie
* DELAUTIER Sébastien
* MONTEIL Thierry
* LE BOTLAN Didier
* AURIOL Guillaume
* DI MERCURIO Sébastien

## Quick User Guide
###Turn the car on and off
* To turn on the car:
  * Toggle the red button to bring the power.
  * Press the START push button (hold it down for a short while).
  * Wait until Raspberry boot up and connect to it using its IP address (written on the board): `ssh pi@10.105.1.xx`
  * When connected start ROS subsystem using :`ros2 launch geicar_start geicar.launch.py`
  * Then, you will get a report of subsystems and be able to control the car using XBOX controler 

* To turn off the car:
	* Use the red button as a switch to turn off the power.

###Use of this repository
* First of all, [fork this repository](https://docs.github.com/en/get-started/quickstart/fork-a-repo) to get yours.
* Then, clone your fresh and new repository on your computer: `git clone https://github.com/<your id>/<your wonderful repo>`
* Have a look in "general" directory for how to connect and work with your car
* For more 'in depth' documentation on a particular subsystem, have a look in following directories:
    * raspberryPI3: Everything about raspberry setup
    * nucleoL476: Stuff about GPS-RTK and IMU
    * nucleoF103: informations on motors control, main power and ultrasonics sensors
    * jetsonNano: Directory containing info on IA, Camera and Lidar
    * simulation: if you want to setup a carla simulation environment

__warning__
You normally do not need to change firmware running in F103 and F476 boards. You main work is on the raspberry and jetson side.


## SPECIAL XCAR_CHIDI

sur eduroam  
ssh pi@10.105.1.167

password = geicar

sudo date --set=”NOV 16 2023 11:31:00”
 (avec la date du jour) 

Dans le répertoire ~/Xcar_chidi 
faire un git pull et un git checkout nom_de_votre_branche

Si vous faites des modifications directement sur la rasperryPi, pensez à faire un git push origin/nom_de_votre_branche pour sauvegarder vos modifications à distance

En étant dans le répertoire  ~/Xcar_chidi/raspberryPi3/ros2_ws/

Pour supprimer les dossiers build précédemment, faites rm -r build/ install/ log/ 
et ensuite colcon build pour la première compilation intégrale

ou 

colcon build --packages-select interfaces 
(ou paquet que vous avez modifié) quand vous modifiez le code déjà compilé sur la pi

Ensuite 

source ~/Xcar_chidi/raspberryPI3/ros2_ws/install/local_setup.bash
Pour ana : source ~/avoidance/Xcar_chidi/raspberryPI3/ros2_ws/install/local_setup.bash
source /opt/ros/humble/setup.bash

pour faire le final :

ros2 launch geicar_start geicar.launch.py 


—-----------------------------------------Jetson—----------------------------------------

ssh pi@10.105.1.167
ssh jetson@192.168.1.10
  mdp : jetson
sudo docker start -ai ros-humble
ou 
Initialiser le docker 
cd ~/Xcar_chidi/jetsonNano 
Pour initialiser le docker 
sudo docker-compose up -d
pour vérifier si le docker est bien là
sudo docker ps 
Lancer le docker
sudo docker exec -ti ros-compose bash
Dans ce cas là le dossier Xcar_chidi de la jetson est directement lié avec celui du docker

Arrêter le docker 
sudo docker stop ros-compose

colcon build (dans le docker,dans jetson dans ros2_ws)
source ~/Xcar_chidi/jetsonNano/ros2_ws/install/local_setup.bash
ros2 launch geicar_start_jetson geicar.jetson.launch.py

+open new terminal + lancer le docker depuis ssh jetson + source (celui du dessu) 
sudo docker exec -ti ros-compose bash
ros2 topic echo --once /scan      ← “--once” pour afficher le topic /scan juste une fois 



Lancer l’IA 
cd ~/ai_processing
python3 listener.py 

INTERFACE WEB

Trois solutions pour y accéder obligatoirement une fois que le ros2 launch est prêt (message webssocket ready on port 9090) : 


Ouvrir le home.html qui est dans ~Xcar_chidi/raspberryPi3/static3/site/public/home.html sur un ordi de l’INSA (seulement car après le réseau de l’INSA ne permet pas d’accéder à d'autres ports)
Connecter la pi à un hotspot (clé 4g, téléphone), récupérer son IP via ifconfig, lancer le app.js qui est dans static3/site en faisant node app.js, ce qui permet de lancer un serveur web sur le port 9091 en local sur la PI, et ensuite y accéder depuis le même hotspot avec un téléphone en tapant http://adresse-ip-de-la-pi:9091 
Sinon, héberger le static3 sur un serveur distant, et il faudra lancer le app.js depuis ce serveur, et donc en complément il faudra depuis ce serveur lancer le fichier ~Xcar_chidi/raspberrypi3/redirect-messages-on-distant.py, puis lancer sur la Pi en local le fichier connect-to-distant.py

Tant que le pourcentage de la batterie en haut à droite n’est pas affiché, c’est que ça ne marche pas.


 




