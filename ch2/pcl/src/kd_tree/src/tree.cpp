#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>
#include <pcl/octree/octree.h>
 
class cloudHandler
{
public:
	cloudHandler()
	{
		pcl_sub=nh.subscribe("pcl_downsampled",10,&cloudHandler::cloudCB,this);
		pcl_pub=nh.advertise<sensor_msgs::PointCloud2>("pcl_part",1);
	}
	
	void cloudCB(const sensor_msgs::PointCloud2 &input)
	{
		pcl::PointCloud<pcl::PointXYZ> cloud;
		pcl::PointCloud<pcl::PointXYZ> cloud_part; 
		sensor_msgs::PointCloud2 output;
 
		pcl::fromROSMsg(input,cloud);  //ROS转换pcl
		//创建八叉树
		float resolution = 128.0f;
		pcl::octree::OctreePointCloudSearch<pcl::PointXYZ> octree(resolution);
		
		octree.setInputCloud(cloud.makeShared());
		octree.addPointsFromInputCloud();
		//定义分区一个中心点
		pcl::PointXYZ center_point;
		center_point.x = -2.9;
		center_point.y = -2.7;
		center_point.z = -0.5;
		//在指定半径内使用八叉树搜寻
		float radius = 0.5;
		std::vector<int>radiusIdx;
		std::vector<float>radiusSQDist;
		if(octree.radiusSearch (center_point,radius,radiusIdx,radiusSQDist)>0)
		{
			for(size_t i = 0;i<radiusIdx.size();++i)
			{
				cloud_part.points.push_back(cloud.points[radiusIdx[i]]);
			}
		}
		
		
 
		//发布
		pcl::toROSMsg(cloud_part,output);
		output.header.frame_id = "odom";
		pcl_pub.publish(output);
		
	}
protected:
	ros::NodeHandle nh;
	ros::Subscriber pcl_sub;
	ros::Publisher pcl_pub;
};
 
 
 
main (int argc, char **argv)
{
	ros::init(argc,argv,"pcl_part");
	cloudHandler handler;
	ros::spin();
	return 0;
}
