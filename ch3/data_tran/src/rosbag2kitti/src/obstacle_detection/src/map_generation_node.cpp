#include "map_generation_node.h"
//This code is to read the .bag files in ROS and decode them into .png and .pcd
//Coordinate system transformation function is optional. 
using namespace cv;

double trans_roll_  = 0.0;
double trans_pitch_ = 0.0;
double trans_yaw_   = 0.0;
double trans_tx_    = 0.0;
double trans_ty_    = 0.0;
double trans_tz_    = 0.0;
Eigen::Affine3f transform_matrix_ = Eigen::Affine3f::Identity();

MapGenerationNode::MapGenerationNode():	lidar_index(0), camera_captured(false), it(nh),
										init_lidar_time(false)
{
    sub_lidar = nh.subscribe("/velodyne_points", 1000, &MapGenerationNode::lidarCallback, this);

	//ros::param::set("~image_transport", "compressed");
	//sub_camera = it.subscribe("/axis/image_rect_color", 1000, &MapGenerationNode::cameraCallback, this);

    ros::spin();
}

//About Lidar Points Cloud (Read & Trans & Save)
void MapGenerationNode::lidarCallback(const sensor_msgs::PointCloud2::ConstPtr& lidar)
{
	if(!init_lidar_time)
	{
		lidar_base_time = lidar->header.stamp.sec * 1e3 + lidar->header.stamp.nsec / 1e6;
		init_lidar_time = true;
	}

	long long lidar_delta_time = lidar->header.stamp.sec * 1e3 + lidar->header.stamp.nsec / 1e6 - lidar_base_time;
	ROS_INFO("get lidar : %lld ms", lidar_delta_time);

	char s[200];
	sprintf(s, "/home/cxl/rosbag2kitti/src/output/pcd/%06lld.pcd", lidar_index); 
	++lidar_index;
	camera_captured = false;

	pcl::fromROSMsg(*lidar, lidar_cloud);

	//Building the transformation matrix
	transform_matrix_.translation() << trans_tx_, trans_ty_, trans_tz_;
  	transform_matrix_.rotate(Eigen::AngleAxisf(trans_yaw_ * M_PI / 180, Eigen::Vector3f::UnitZ()));
  	transform_matrix_.rotate(Eigen::AngleAxisf(trans_pitch_ * M_PI / 180, Eigen::Vector3f::UnitY()));
  	transform_matrix_.rotate(Eigen::AngleAxisf(trans_roll_ * M_PI / 180, Eigen::Vector3f::UnitX()));

  	//Transformation
	pcl::PointCloud<pcl::PointXYZI>::Ptr trans_cloud_ptr(new pcl::PointCloud<pcl::PointXYZI>);
  	pcl::transformPointCloud(lidar_cloud, *trans_cloud_ptr, transform_matrix_);
	//Save in .pcd
	pcl::io::savePCDFileASCII (s, *trans_cloud_ptr);
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "map_generation");
    MapGenerationNode mapgeneration;
    return 0;
}
