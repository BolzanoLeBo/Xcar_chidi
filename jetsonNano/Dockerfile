FROM arm64v8/ros:humble-ros-base
RUN apt-get update
RUN apt-get install -y openssh-server net-tools nano vim apt-utils ufw iputils-ping software-properties-common
RUN add-apt-repository universe
RUN apt-get update
RUN apt-get install -y \
  ros-rolling-ros-base \
  ros-dev-tools \
  ros-humble-navigation2 \
  ros-humble-nav2-bringup \
  v4l-utils \
  python3-rosdep \
  git
RUN apt-get install -y ros-humble-joint-state-publisher-gui ros-humble-xacro python3-pip

RUN pip install catkin_pkg

WORKDIR /root/
COPY .bashrc /root/.bashrc
RUN git clone https://github.com/BolzanoLeBo/Xcar_chidi.git
WORKDIR /root/Xcar_chidi/jetsonNano/ros2_ws/

RUN rosdep update
RUN rosdep install --from-paths src --ignore-src -y

WORKDIR /root/
RUN rm -rf Xcar_chidi
# RUN . /opt/ros/humble/setup.sh && colcon build
