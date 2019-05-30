# ROS base
FROM ros:melodic-robot

# Create working directory
WORKDIR /tinkerforge

# Copy in source code
COPY . /tinkerforge

# Build the project
RUN /bin/bash -c "source /opt/ros/melodic/setup.sh && catkin_make"

# Launch command
CMD stdbuf -o L /tinkerforge/imu_brick.sh
