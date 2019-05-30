#!/bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source /opt/ros/melodic/setup.bash && source $DIR/devel/setup.bash && roslaunch imu_brick imu_brick
