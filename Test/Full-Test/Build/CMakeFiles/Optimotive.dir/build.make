# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/GitHub/Optimotive/Tests/Full-Test/Build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/GitHub/Optimotive/Tests/Full-Test/Build

# Include any dependencies generated for this target.
include CMakeFiles/Optimotive.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Optimotive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Optimotive.dir/flags.make

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o: CMakeFiles/Optimotive.dir/flags.make
CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o: /home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/GitHub/Optimotive/Tests/Full-Test/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o -c /home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp > CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.i

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.s

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.requires:
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.requires

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.provides: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.requires
	$(MAKE) -f CMakeFiles/Optimotive.dir/build.make CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.provides.build
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.provides

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.provides.build: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o: CMakeFiles/Optimotive.dir/flags.make
CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o: /home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/GitHub/Optimotive/Tests/Full-Test/Build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o -c /home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp > CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.i

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.s

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.requires:
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.requires

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.provides: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Optimotive.dir/build.make CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.provides.build
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.provides

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.provides.build: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o: CMakeFiles/Optimotive.dir/flags.make
CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o: /home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/GitHub/Optimotive/Tests/Full-Test/Build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o -c /home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp > CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.i

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.s

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.requires:
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.requires

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.provides: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.requires
	$(MAKE) -f CMakeFiles/Optimotive.dir/build.make CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.provides.build
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.provides

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.provides.build: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o: CMakeFiles/Optimotive.dir/flags.make
CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o: /home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/GitHub/Optimotive/Tests/Full-Test/Build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o -c /home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp > CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.i

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp -o CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.s

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.requires:
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.requires

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.provides: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Optimotive.dir/build.make CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.provides

CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.provides.build: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o

# Object files for target Optimotive
Optimotive_OBJECTS = \
"CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o" \
"CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o" \
"CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o" \
"CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o"

# External object files for target Optimotive
Optimotive_EXTERNAL_OBJECTS =

Optimotive: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o
Optimotive: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o
Optimotive: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o
Optimotive: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o
Optimotive: CMakeFiles/Optimotive.dir/build.make
Optimotive: /usr/local/lib/libopencv_videostab.so.3.1.0
Optimotive: /usr/local/lib/libopencv_videoio.so.3.1.0
Optimotive: /usr/local/lib/libopencv_video.so.3.1.0
Optimotive: /usr/local/lib/libopencv_superres.so.3.1.0
Optimotive: /usr/local/lib/libopencv_stitching.so.3.1.0
Optimotive: /usr/local/lib/libopencv_shape.so.3.1.0
Optimotive: /usr/local/lib/libopencv_photo.so.3.1.0
Optimotive: /usr/local/lib/libopencv_objdetect.so.3.1.0
Optimotive: /usr/local/lib/libopencv_ml.so.3.1.0
Optimotive: /usr/local/lib/libopencv_imgproc.so.3.1.0
Optimotive: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
Optimotive: /usr/local/lib/libopencv_highgui.so.3.1.0
Optimotive: /usr/local/lib/libopencv_flann.so.3.1.0
Optimotive: /usr/local/lib/libopencv_features2d.so.3.1.0
Optimotive: /usr/local/lib/libopencv_core.so.3.1.0
Optimotive: /usr/local/lib/libopencv_calib3d.so.3.1.0
Optimotive: /usr/local/lib/libwiringPi.so
Optimotive: /usr/local/lib/libopencv_features2d.so.3.1.0
Optimotive: /usr/local/lib/libopencv_ml.so.3.1.0
Optimotive: /usr/local/lib/libopencv_highgui.so.3.1.0
Optimotive: /usr/local/lib/libopencv_videoio.so.3.1.0
Optimotive: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
Optimotive: /usr/local/lib/libopencv_flann.so.3.1.0
Optimotive: /usr/local/lib/libopencv_video.so.3.1.0
Optimotive: /usr/local/lib/libopencv_imgproc.so.3.1.0
Optimotive: /usr/local/lib/libopencv_core.so.3.1.0
Optimotive: CMakeFiles/Optimotive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Optimotive"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Optimotive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Optimotive.dir/build: Optimotive
.PHONY : CMakeFiles/Optimotive.dir/build

CMakeFiles/Optimotive.dir/requires: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/Motor.cpp.o.requires
CMakeFiles/Optimotive.dir/requires: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/MotorManager.cpp.o.requires
CMakeFiles/Optimotive.dir/requires: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/FaceDetector.cpp.o.requires
CMakeFiles/Optimotive.dir/requires: CMakeFiles/Optimotive.dir/home/pi/GitHub/Optimotive/Tests/Full-Test/src/main.cpp.o.requires
.PHONY : CMakeFiles/Optimotive.dir/requires

CMakeFiles/Optimotive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Optimotive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Optimotive.dir/clean

CMakeFiles/Optimotive.dir/depend:
	cd /home/pi/GitHub/Optimotive/Tests/Full-Test/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/GitHub/Optimotive/Tests/Full-Test/Build /home/pi/GitHub/Optimotive/Tests/Full-Test/Build /home/pi/GitHub/Optimotive/Tests/Full-Test/Build /home/pi/GitHub/Optimotive/Tests/Full-Test/Build /home/pi/GitHub/Optimotive/Tests/Full-Test/Build/CMakeFiles/Optimotive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Optimotive.dir/depend
