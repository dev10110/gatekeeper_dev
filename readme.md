# Gatekeeper

## Usage
from this directory:
- `docker compose build`
- `docker compose up &`

Enter the docker container. You should now be at `/root/colcon_ws`

- `cd /root/PX4-Autopilot`
- `DONT_RUN=1 make px4_sitl_rtps gazebo`
- `cd /root/colcon_ws`
- `colcon build --symlink-install`


## experiment: 
- `ros2 launch experiment launch_exp.py`
- `ros2 run dasc_robot trajectory_follower --ros-args -p use_sim_time:=True` 
- `ros2 run gatekeeper gatekeeper`

- `ros2 run gatekeeper nominal_trajectory` OR
- `ros2 run gatekeeper joystick_controller`
