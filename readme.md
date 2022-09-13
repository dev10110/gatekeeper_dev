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

