# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/mriTesting/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/mriTesting/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/status_frame_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/status_frame_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/status_frame_lib.dir/flags.make

CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o: CMakeFiles/status_frame_lib.dir/flags.make
CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o: ../src/gui/status_frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o -c /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/src/gui/status_frame.cpp

CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/src/gui/status_frame.cpp > CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.i

CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/src/gui/status_frame.cpp -o CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.s

CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.requires:

.PHONY : CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.requires

CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.provides: CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.requires
	$(MAKE) -f CMakeFiles/status_frame_lib.dir/build.make CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.provides.build
.PHONY : CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.provides

CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.provides.build: CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o


# Object files for target status_frame_lib
status_frame_lib_OBJECTS = \
"CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o"

# External object files for target status_frame_lib
status_frame_lib_EXTERNAL_OBJECTS =

devel/lib/libstatus_frame_lib.so: CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o
devel/lib/libstatus_frame_lib.so: CMakeFiles/status_frame_lib.dir/build.make
devel/lib/libstatus_frame_lib.so: CMakeFiles/status_frame_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library devel/lib/libstatus_frame_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/status_frame_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/status_frame_lib.dir/build: devel/lib/libstatus_frame_lib.so

.PHONY : CMakeFiles/status_frame_lib.dir/build

CMakeFiles/status_frame_lib.dir/requires: CMakeFiles/status_frame_lib.dir/src/gui/status_frame.cpp.o.requires

.PHONY : CMakeFiles/status_frame_lib.dir/requires

CMakeFiles/status_frame_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/status_frame_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/status_frame_lib.dir/clean

CMakeFiles/status_frame_lib.dir/depend:
	cd /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/cmake-build-debug /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/cmake-build-debug /home/xxx91/ros_ws/src/catheter_arduino_controller/src/catheter_arduino_gui/cmake-build-debug/CMakeFiles/status_frame_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/status_frame_lib.dir/depend

