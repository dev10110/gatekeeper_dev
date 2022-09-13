FROM px4io/px4-dev-ros2-foxy:2021-12-11

RUN apt-get update && apt-get install -y --no-install-recommends vim tmux

# install gazebo and octomap
RUN apt-get install -y ros-foxy-gazebo-ros-pkgs # ros-foxy-octomap ros-foxy-octomap-mapping

# install joystick
RUN apt-get install -y ros-foxy-joy

# install pcl-conversion
RUN apt-get install ros-foxy-pcl-conversions

# source folders
WORKDIR /root/colcon_ws
RUN echo 'source /opt/ros/foxy/setup.bash' >> ~/.bashrc
RUN echo 'source /root/colcon_ws/install/setup.bash' >> ~/.bashrc

WORKDIR /root/colcon_ws
