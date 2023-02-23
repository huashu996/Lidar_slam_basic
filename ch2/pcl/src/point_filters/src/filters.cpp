#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/statistical_outlier_removal.h>
 
class cloudHandler
{
public:
	cloudHandler()
	{
		//接收pcl_output节点的数据，在cloudCB回调函数进行处理，以pcl_filtered节点发出去
		pcl_sub = nh.subscribe("pcl_output",10,&cloudHandler::cloudCB, this);//定义接收者
		pcl_pub = nh.advertise<sensor_msgs::PointCloud2>("pcl_filtered",1);//定义发布者
	}
	void cloudCB(const sensor_msgs::PointCloud2& input)
	{
		//创建接收点云 发出点云 发出消息的变量
		pcl::PointCloud<pcl::PointXYZ> cloud;
		pcl::PointCloud<pcl::PointXYZ> cloud_filtered;
		sensor_msgs::PointCloud2 output;
		//把ROS消息转化为pcl
		pcl::fromROSMsg(input,cloud);
		
		//定义一个滤波分析算法
		pcl::StatisticalOutlierRemoval<pcl::PointXYZ> statFilter;
		statFilter.setInputCloud(cloud.makeShared()); //cloud传入
		statFilter.setMeanK(10);
		statFilter.setStddevMulThresh(0.2);
		statFilter.filter(cloud_filtered); //cloud_filtered传出
		
		//将PCL类型 cloud_filtered的数据 转化成ROS类型 output的数据
		pcl::toROSMsg(cloud_filtered,output);
		pcl_pub.publish(output);
		
	}
protected:
	//创建节点 接受者 发布者
	ros::NodeHandle nh;
	ros::Subscriber pcl_sub;
	ros::Publisher pcl_pub;
 
};
 
 
 
main (int argc,char** argv)
{
	ros::init(argc,argv,"pcl_filter");
	cloudHandler handler;
	ros::spin();
 
	return 0;
}
