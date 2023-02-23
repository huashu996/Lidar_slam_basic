#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <sensor_msgs/PointCloud2.h>
 
class cloudHandler
{
public:
	cloudHandler()
	{
		//接收pcl_output节点的数据，在cloudCB回调函数进行处理，以pcl_filtered节点发出去
		pcl_sub = nh.subscribe("/pcl_output",10,&cloudHandler::cloudCB, this);//定义接收者
		pcl_pub = nh.advertise<sensor_msgs::PointCloud2>("pcl_segmented",1);//定义发布者
		ind_pub = nh.advertise<pcl_msgs::PointIndices>("point_indices",1);//PointIndices消息储存一个点云中心点的索引
		coef_pub = nh.advertise<pcl_msgs::ModelCoefficients>("planar_coef",1);//ModeCoefficients消息储存一个数学模型的系数
 
	}
	void cloudCB(const sensor_msgs::PointCloud2& input)
	{
		//创建接收点云 发出点云 发出消息的变量
		pcl::PointCloud<pcl::PointXYZ> cloud;
		pcl::PointCloud<pcl::PointXYZ> cloud_segmented;
		//把传入的ROS消息转化为pcl
		pcl::fromROSMsg(input,cloud);
		//创建两个消息对象
		pcl::ModelCoefficients coefficients;
		pcl::PointIndices::Ptr inliers(new pcl::PointIndices());
		
		//定义分割算法模型
		pcl::SACSegmentation<pcl::PointXYZ> segmentation;//创建算法对象
		segmentation.setModelType(pcl::SACMODEL_PLANE);//期望匹配的数学模型
		segmentation.setMethodType(pcl::SAC_RANSAC);//用到的算法
		segmentation.setMaxIterations(1000);//定义最大迭代
		segmentation.setDistanceThreshold(0.01);//到模型最大距离
		segmentation.setInputCloud(cloud.makeShared());//输入
		segmentation.segment(*inliers, coefficients);//分割
		
		//将内点转化成ROS消息
		pcl_msgs::ModelCoefficients ros_coefficients;
		pcl_conversions::fromPCL(coefficients, ros_coefficients);
		ros_coefficients.header.stamp = input.header.stamp;
		coef_pub.publish(ros_coefficients);
		//将模型系数转化成ROS消息
		pcl_msgs::PointIndices ros_inliers;
		pcl_conversions::fromPCL(*inliers,ros_inliers);
		ros_inliers.header.stamp = input.header.stamp;
		ind_pub.publish(ros_inliers);
		
		//提取分割点云
		pcl::ExtractIndices<pcl::PointXYZ> extract;
		extract.setInputCloud(cloud.makeShared());
		extract.setIndices(inliers);
		extract.setNegative(false);
		extract.filter(cloud_segmented);//分割后储存在cloud_segmented
		
		sensor_msgs::PointCloud2 output;
		//将PCL类型 cloud_filtered的数据 转化成ROS类型 output的数据
		pcl::toROSMsg(cloud_segmented,output);
		pcl_pub.publish(output);
		
	}
protected:
	//创建节点 接受者 发布者
	ros::NodeHandle nh;
	ros::Subscriber pcl_sub;
	ros::Publisher pcl_pub, ind_pub, coef_pub;
 
};
 
main (int argc,char** argv)
{
	ros::init(argc,argv,"pcl_segment");
	cloudHandler handler;
	ros::spin();
	return 0;
}
