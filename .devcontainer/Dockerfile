ARG DOCKER_REPO
ARG ROS_DISTRO
ARG DISTRO_VERSION
FROM $DOCKER_REPO:$ROS_DISTRO$DISTRO_VERSION

# Create the user
ARG USERNAME=harw
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y git ssh python3-pip python-is-python3 python3-catkin-tools neovim build-essential
ENV SHELL /bin/bash

# Switch to user
USER $USERNAME
RUN sudo usermod --append --groups video $USERNAME

# Rosdep update
RUN rosdep update

# Source ROS environment
RUN echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> /home/$USERNAME/.bashrc
CMD ["/bin/bash"]