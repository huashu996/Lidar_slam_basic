//迭代最近点ICP算法
#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>
 
class cloudHandler
{
public:
	cloudHandler()
	{
		pcl_sub=nh.subscribe("/pcl_output",10,&cloudHandler::cloudCB,this);
		pcl_pub=nh.advertise<sensor_msgs::PointCloud2>("pcl_matched",1);
	}
	
	void cloudCB(const sensor_msgs::PointCloud2 &input)
	{
		pcl::PointCloud<pcl::PointXYZ> cloud_in; //要转换的点云
		pcl::PointCloud<pcl::PointXYZ> cloud_out; //与点云对齐的点云
		pcl::PointCloud<pcl::PointXYZ> cloud_aligned; //最终点云
 
		sensor_msgs::PointCloud2 output;
		pcl::fromROSMsg(input,cloud_in);  //ROS转换pcl
		cloud_out = cloud_in;
		for(size_t i=0; i<cloud_in.points.size();i++)
		{
			cloud_out.points[i].x = cloud_in.points[i].x+0.7f;//点云平移
		}
		//对两个点云进行配准
		pcl::IterativeClosestPoint<pcl::PointXYZ,pcl::PointXYZ>icp;
		//in和移动的out进行配准
		icp.setInputSource(cloud_in.makeShared());
		icp.setInputTarget(cloud_out.makeShared());
		
		icp.setMaxCorrespondenceDistance(5);
		icp.setMaximumIterations(100);
		icp.setTransformationEpsilon(1e-12);
		icp.setEuclideanFitnessEpsilon(0.1);
		icp.align(cloud_aligned);
		//发布
		pcl::toROSMsg(cloud_aligned,output);
		pcl_pub.publish(output);
		
	}
protected:
	ros::NodeHandle nh;
	ros::Subscriber pcl_sub;
	ros::Publisher pcl_pub;
};
 
 
 
main (int argc, char **argv)
{
	ros::init(argc,argv,"pcl_matching");
	cloudHandler handler;
	ros::spin();
	return 0;
}
