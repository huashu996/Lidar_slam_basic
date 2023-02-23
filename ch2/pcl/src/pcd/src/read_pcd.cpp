//加载PCD文件并且将点云发布为ROS消息
#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
 
main(int argc, char **argv)
{
	ros::init (argc,argv,"pcl_read");//定义节点
	ros::NodeHandle nh;
	ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2>("pcl_output",1);
	
	sensor_msgs::PointCloud2 output;
	pcl::PointCloud<pcl::PointXYZ> cloud;
	
	pcl::io::loadPCDFile("/home/cxl/slambook2/lidar_slam_basic/ch2/pcl/src/pcd/src/test.pcd",cloud);//加载pcd文件 为cloud
	
	pcl::toROSMsg(cloud,output);
	output.header.frame_id="odom";
	
		//发布消息
	ros::Rate loop_rate(1);
	while(ros::ok())
	{
		pcl_pub.publish(output);
		ros::spinOnce();
		loop_rate.sleep();
	
	}
	
	return 0;
}

