//将接收的点云保存在PCD文件中
#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
 
void cloudCB(const sensor_msgs::PointCloud2 &input)
{
	pcl::PointCloud<pcl::PointXYZ> cloud;
	pcl::fromROSMsg(input,cloud);
	pcl::io::savePCDFileASCII ("write_pcd_test.pcd",cloud);
}
 
main (int argc,char **argv)
{
	ros::init(argc,argv,"pcl_write");
	
	ros::NodeHandle nh;
	//定义接受者
	ros::Subscriber bat_sub = nh.subscribe("pcl_output",10,cloudCB);//cloudCB为回调函数
	ros::spin();
	return 0;
}
