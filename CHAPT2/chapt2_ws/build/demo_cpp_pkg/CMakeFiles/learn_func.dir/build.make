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
CMAKE_SOURCE_DIR = /home/ros2/CHAPT2/chapt2_ws/src/demo_cpp_pkg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ros2/CHAPT2/chapt2_ws/build/demo_cpp_pkg

# Include any dependencies generated for this target.
include CMakeFiles/learn_func.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learn_func.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learn_func.dir/flags.make

CMakeFiles/learn_func.dir/src/learn_func.cpp.o: CMakeFiles/learn_func.dir/flags.make
CMakeFiles/learn_func.dir/src/learn_func.cpp.o: /home/ros2/CHAPT2/chapt2_ws/src/demo_cpp_pkg/src/learn_func.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ros2/CHAPT2/chapt2_ws/build/demo_cpp_pkg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learn_func.dir/src/learn_func.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn_func.dir/src/learn_func.cpp.o -c /home/ros2/CHAPT2/chapt2_ws/src/demo_cpp_pkg/src/learn_func.cpp

CMakeFiles/learn_func.dir/src/learn_func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn_func.dir/src/learn_func.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ros2/CHAPT2/chapt2_ws/src/demo_cpp_pkg/src/learn_func.cpp > CMakeFiles/learn_func.dir/src/learn_func.cpp.i

CMakeFiles/learn_func.dir/src/learn_func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn_func.dir/src/learn_func.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ros2/CHAPT2/chapt2_ws/src/demo_cpp_pkg/src/learn_func.cpp -o CMakeFiles/learn_func.dir/src/learn_func.cpp.s

# Object files for target learn_func
learn_func_OBJECTS = \
"CMakeFiles/learn_func.dir/src/learn_func.cpp.o"

# External object files for target learn_func
learn_func_EXTERNAL_OBJECTS =

learn_func: CMakeFiles/learn_func.dir/src/learn_func.cpp.o
learn_func: CMakeFiles/learn_func.dir/build.make
learn_func: CMakeFiles/learn_func.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ros2/CHAPT2/chapt2_ws/build/demo_cpp_pkg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable learn_func"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learn_func.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learn_func.dir/build: learn_func

.PHONY : CMakeFiles/learn_func.dir/build

CMakeFiles/learn_func.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learn_func.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learn_func.dir/clean

CMakeFiles/learn_func.dir/depend:
	cd /home/ros2/CHAPT2/chapt2_ws/build/demo_cpp_pkg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ros2/CHAPT2/chapt2_ws/src/demo_cpp_pkg /home/ros2/CHAPT2/chapt2_ws/src/demo_cpp_pkg /home/ros2/CHAPT2/chapt2_ws/build/demo_cpp_pkg /home/ros2/CHAPT2/chapt2_ws/build/demo_cpp_pkg /home/ros2/CHAPT2/chapt2_ws/build/demo_cpp_pkg/CMakeFiles/learn_func.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learn_func.dir/depend

