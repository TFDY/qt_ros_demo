#ifndef QMYNODE_HPP
#define QMYNODE_HPP
#include <QThread>
#include <ros/ros.h>
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
class QMyNode : public QThread
{
    Q_OBJECT
public:
    QMyNode()
    {
        // 初始化 ROS 客户端；
        // 传入节点名称
        int argc = 0;
        char *argv[] = {0};
        ros::init(argc, argv, "erGouZi");
        ros::start(); // explicitly needed since our nodehandle is going out of scope.
        // 创建节点句柄；
        this->_nh = new ros::NodeHandle();
        this->_pubp = _nh->advertise<geometry_msgs::Twist>("hello", 10);
        this->_pub_is_ok = 0;
    }
    // 设置话题和pub
    void _set_pub(std::string topic_name)
    {
        // 创建发布者
        this->_pubp = _nh->advertise<geometry_msgs::Twist>(topic_name, 10);
        _pub_is_ok = 1;
    }
    bool _pub_is_ok;
    // 发送消息
    void _pub_msgs(int udlr)
    {
        /* ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear:{x: 2.0,y: 0.0,z: 0.0},angular:{x: 0.0,y: 0.0,z: 1.8}}" */
        geometry_msgs::Twist twist;
        switch (udlr)
        {
        case 0: // 前
            twist.linear.x = 1.0;
            break;
        case 1: // 后
            twist.linear.x = -1.0;
            break;
        case 2: // 左
            twist.angular.z = 1.8;
            break;
        case 3: // 右
            twist.angular.z = -1.8;
            break;
        case 5: // 左前
            twist.linear.x = 1.0;
            twist.angular.z = 1.8;
            break;
        case 6: // 右前
            twist.linear.x = 1.0;
            twist.angular.z = -1.8;
            break;
        case 7: // 左后
            twist.linear.x = -1.0;
            twist.angular.z = 1.8;
            break;
        case 8: // 右后
            twist.linear.x = -1.0;
            twist.angular.z = -1.8;
            break;

        default:
            twist.linear.x = 0;
            twist.angular.z = 0;
            break;
        }
        this->_pubp.publish(twist);
    }

private:
    ros::Publisher _pubp;
    ros::NodeHandle* _nh;
signals:
};
#endif // RCLCOMM_HPP