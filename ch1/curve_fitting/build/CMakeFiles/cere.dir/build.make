# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/build

# Include any dependencies generated for this target.
include CMakeFiles/cere.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cere.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cere.dir/flags.make

CMakeFiles/cere.dir/ceresCurveFitting.cpp.o: CMakeFiles/cere.dir/flags.make
CMakeFiles/cere.dir/ceresCurveFitting.cpp.o: ../ceresCurveFitting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cere.dir/ceresCurveFitting.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cere.dir/ceresCurveFitting.cpp.o -c /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/ceresCurveFitting.cpp

CMakeFiles/cere.dir/ceresCurveFitting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cere.dir/ceresCurveFitting.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/ceresCurveFitting.cpp > CMakeFiles/cere.dir/ceresCurveFitting.cpp.i

CMakeFiles/cere.dir/ceresCurveFitting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cere.dir/ceresCurveFitting.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/ceresCurveFitting.cpp -o CMakeFiles/cere.dir/ceresCurveFitting.cpp.s

# Object files for target cere
cere_OBJECTS = \
"CMakeFiles/cere.dir/ceresCurveFitting.cpp.o"

# External object files for target cere
cere_EXTERNAL_OBJECTS =

cere: CMakeFiles/cere.dir/ceresCurveFitting.cpp.o
cere: CMakeFiles/cere.dir/build.make
cere: /usr/local/lib/libopencv_gapi.so.4.7.0
cere: /usr/local/lib/libopencv_highgui.so.4.7.0
cere: /usr/local/lib/libopencv_ml.so.4.7.0
cere: /usr/local/lib/libopencv_objdetect.so.4.7.0
cere: /usr/local/lib/libopencv_photo.so.4.7.0
cere: /usr/local/lib/libopencv_stitching.so.4.7.0
cere: /usr/local/lib/libopencv_video.so.4.7.0
cere: /usr/local/lib/libopencv_videoio.so.4.7.0
cere: /usr/local/lib/libceres.a
cere: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
cere: /usr/local/lib/libopencv_dnn.so.4.7.0
cere: /usr/local/lib/libopencv_calib3d.so.4.7.0
cere: /usr/local/lib/libopencv_features2d.so.4.7.0
cere: /usr/local/lib/libopencv_flann.so.4.7.0
cere: /usr/local/lib/libopencv_imgproc.so.4.7.0
cere: /usr/local/lib/libopencv_core.so.4.7.0
cere: /usr/local/lib/libglog.so.0.7.0
cere: /usr/lib/x86_64-linux-gnu/libgflags.so.2.2.2
cere: /usr/lib/x86_64-linux-gnu/libspqr.so
cere: /usr/lib/x86_64-linux-gnu/libtbb.so
cere: /usr/lib/x86_64-linux-gnu/libcholmod.so
cere: /usr/lib/x86_64-linux-gnu/libccolamd.so
cere: /usr/lib/x86_64-linux-gnu/libcamd.so
cere: /usr/lib/x86_64-linux-gnu/libcolamd.so
cere: /usr/lib/x86_64-linux-gnu/libamd.so
cere: /usr/lib/x86_64-linux-gnu/libmkl_intel_lp64.so
cere: /usr/lib/x86_64-linux-gnu/libmkl_intel_thread.so
cere: /usr/lib/x86_64-linux-gnu/libmkl_core.so
cere: /usr/lib/x86_64-linux-gnu/libiomp5.so
cere: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
cere: /usr/lib/x86_64-linux-gnu/librt.so
cere: /usr/local/lib/libmetis.so
cere: /usr/lib/x86_64-linux-gnu/libcxsparse.so
cere: /usr/lib/x86_64-linux-gnu/libmkl_intel_lp64.so
cere: /usr/lib/x86_64-linux-gnu/libmkl_intel_thread.so
cere: /usr/lib/x86_64-linux-gnu/libmkl_core.so
cere: /usr/lib/x86_64-linux-gnu/libiomp5.so
cere: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
cere: /usr/lib/x86_64-linux-gnu/librt.so
cere: /usr/local/lib/libmetis.so
cere: /usr/lib/x86_64-linux-gnu/libcxsparse.so
cere: CMakeFiles/cere.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cere"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cere.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cere.dir/build: cere

.PHONY : CMakeFiles/cere.dir/build

CMakeFiles/cere.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cere.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cere.dir/clean

CMakeFiles/cere.dir/depend:
	cd /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/build /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/build /home/cxl/workspace/lidar_slam_basic/ch1/curve_fitting/build/CMakeFiles/cere.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cere.dir/depend
