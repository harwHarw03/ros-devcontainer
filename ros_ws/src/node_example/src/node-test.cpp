#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_node");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10); // 10 Hz

    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "Hello from ROS Node";

        pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
