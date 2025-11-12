ARG DOCKER_REPO
ARG ROS_DISTRO
ARG DISTRO_VERSION
FROM $DOCKER_REPO:$ROS_DISTRO$DISTRO_VERSION

# Create the user
ARG USERNAME=harw
ARG USER_UID=1000
ARG USER_GID=${USER_UID}
RUN groupadd --gid ${USER_GID} ${USERNAME} \
    && useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} \
    && apt-get update && apt-get install -y sudo \
    && echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/${USERNAME} \
    && chmod 0440 /etc/sudoers.d/${USERNAME}

RUN apt-get update && apt-get install -y \
    git ssh python3-pip python-is-python3 neovim build-essential \
    python3-colcon-common-extensions python3-rosdep

RUN rosdep init 2>/dev/null || true && rosdep update

ENV SHELL /bin/bash

# Switch to user
USER ${USERNAME}
RUN sudo usermod --append --groups video ${USERNAME}
RUN sudo usermod -aG dialout ${USERNAME}

RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> /home/${USERNAME}/.bashrc

CMD ["/bin/bash"]
