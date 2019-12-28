#include <ros/ros.h>
#include <iostream>
#include <programprojekt/direction.h>
#include <geometry_msgs/Twist.h>
int dir{};

void callback(const programprojekt::direction &submsg)
{
    dir = submsg.dir;
}

geometry_msgs::Twist calculation(geometry_msgs::Twist &msg)
{
    switch (dir)
    {
    case 0:
        msg.linear.x = 0;
        msg.angular.z = 0;
        break;

    case 1:
        msg.linear.x = 2;
        msg.angular.z = 2;
        std::cout << "Turning Left\n";
        break;

    case 2:
        msg.linear.x = 2;
        msg.angular.z = -2;
        std::cout << "Turning Right\n";
        break;

    case 3:
        msg.linear.x = 4;
        msg.angular.z = 0;
        std::cout << "Going Straight\n";
        break;
    }
    return msg;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "calculation");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("Turtledir", 1, callback);
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
    programprojekt::direction dirmsg;
    geometry_msgs::Twist msg;
    ros::Rate loop_rate(5);

    while (ros::ok())
    {
        pub.publish(calculation(msg));
        dir = 0;
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}