// *** Author:  Group B225
// *** Project: Miniproject
// *** Node:    calculation
// *** Created: 31-12-2019

#include <ros/ros.h>
#include <iostream>
#include <programprojekt/direction.h>

int interface()
{
    int direction;
    std::cout << "Welcome to the turtlesim mover\n"
              << "Here is your options: \n";

    std::cout << "1 - Move turtle left\n2 - Move turtle right\n3 - Move turtle straight\n";
    std::cout << "Type your answer: ";
    std::cin >> direction;
    while (std::cin.fail() || direction < 1 || direction > 3)
    {
        std::cout << "That was not a character of the correct type or not within the number range, please try again\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Type your answer: ";
        std::cin >> direction;
    }
    std::cout << "\nYou chose " << direction << std::endl;

    return direction;
}

int interface2()
{
    int direction;
    std::cout << "Here is your options again: \n";

    std::cout << "1 - Move turtle left\n2 - Move turtle right\n3 - Move turtle straight\n";
    std::cout << "Type your answer: ";
    std::cin >> direction;
    while (std::cin.fail() || direction < 1 || direction > 3)
    {
        std::cout << "That was not a character of the correct type or not within the number range, please try again\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Type your answer: ";
        std::cin >> direction;
    }
    std::cout << "\nYou chose " << direction << std::endl;

    return direction;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "interface");
    ros::NodeHandle n;
    ros::Publisher dir_pub = n.advertise<programprojekt::direction>("Turtledir", 1);
    programprojekt::direction msg;
    int dir{};
    for (size_t i = 0; i < 1; i++)
    {
        dir = interface();
        msg.dir = dir;
        dir_pub.publish(msg);
    }

    while (ros::ok())
    {
        dir = interface2();
        msg.dir = dir;
        dir_pub.publish(msg);
    }

    return 0;
}
