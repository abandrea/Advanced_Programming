# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2

# Include any dependencies generated for this target.
include CMakeFiles/forward_euler_module.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/forward_euler_module.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/forward_euler_module.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/forward_euler_module.dir/flags.make

CMakeFiles/forward_euler_module.dir/bindings.cpp.o: CMakeFiles/forward_euler_module.dir/flags.make
CMakeFiles/forward_euler_module.dir/bindings.cpp.o: bindings.cpp
CMakeFiles/forward_euler_module.dir/bindings.cpp.o: CMakeFiles/forward_euler_module.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/forward_euler_module.dir/bindings.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/forward_euler_module.dir/bindings.cpp.o -MF CMakeFiles/forward_euler_module.dir/bindings.cpp.o.d -o CMakeFiles/forward_euler_module.dir/bindings.cpp.o -c /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2/bindings.cpp

CMakeFiles/forward_euler_module.dir/bindings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/forward_euler_module.dir/bindings.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2/bindings.cpp > CMakeFiles/forward_euler_module.dir/bindings.cpp.i

CMakeFiles/forward_euler_module.dir/bindings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/forward_euler_module.dir/bindings.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2/bindings.cpp -o CMakeFiles/forward_euler_module.dir/bindings.cpp.s

# Object files for target forward_euler_module
forward_euler_module_OBJECTS = \
"CMakeFiles/forward_euler_module.dir/bindings.cpp.o"

# External object files for target forward_euler_module
forward_euler_module_EXTERNAL_OBJECTS =

forward_euler_module.cpython-312-darwin.so: CMakeFiles/forward_euler_module.dir/bindings.cpp.o
forward_euler_module.cpython-312-darwin.so: CMakeFiles/forward_euler_module.dir/build.make
forward_euler_module.cpython-312-darwin.so: CMakeFiles/forward_euler_module.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module forward_euler_module.cpython-312-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/forward_euler_module.dir/link.txt --verbose=$(VERBOSE)
	/Library/Developer/CommandLineTools/usr/bin/strip -x /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2/forward_euler_module.cpython-312-darwin.so

# Rule to build all files generated by this target.
CMakeFiles/forward_euler_module.dir/build: forward_euler_module.cpython-312-darwin.so
.PHONY : CMakeFiles/forward_euler_module.dir/build

CMakeFiles/forward_euler_module.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/forward_euler_module.dir/cmake_clean.cmake
.PHONY : CMakeFiles/forward_euler_module.dir/clean

CMakeFiles/forward_euler_module.dir/depend:
	cd /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2 /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2 /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2 /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2 /Users/andrea.buscema/Desktop/ap_exam/andrea/EXAM/project_sim2/CMakeFiles/forward_euler_module.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/forward_euler_module.dir/depend

