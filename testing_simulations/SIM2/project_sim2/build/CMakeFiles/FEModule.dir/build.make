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
CMAKE_SOURCE_DIR = /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build

# Include any dependencies generated for this target.
include CMakeFiles/FEModule.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FEModule.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FEModule.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FEModule.dir/flags.make

CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o: CMakeFiles/FEModule.dir/flags.make
CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o: /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/bindings/pybind_sim2.cpp
CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o: CMakeFiles/FEModule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o -MF CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o.d -o CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o -c /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/bindings/pybind_sim2.cpp

CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/bindings/pybind_sim2.cpp > CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.i

CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/bindings/pybind_sim2.cpp -o CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.s

# Object files for target FEModule
FEModule_OBJECTS = \
"CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o"

# External object files for target FEModule
FEModule_EXTERNAL_OBJECTS =

FEModule.cpython-312-darwin.so: CMakeFiles/FEModule.dir/bindings/pybind_sim2.cpp.o
FEModule.cpython-312-darwin.so: CMakeFiles/FEModule.dir/build.make
FEModule.cpython-312-darwin.so: CMakeFiles/FEModule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module FEModule.cpython-312-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FEModule.dir/link.txt --verbose=$(VERBOSE)
	/Library/Developer/CommandLineTools/usr/bin/strip -x /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build/FEModule.cpython-312-darwin.so

# Rule to build all files generated by this target.
CMakeFiles/FEModule.dir/build: FEModule.cpython-312-darwin.so
.PHONY : CMakeFiles/FEModule.dir/build

CMakeFiles/FEModule.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FEModule.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FEModule.dir/clean

CMakeFiles/FEModule.dir/depend:
	cd /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2 /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2 /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build /Users/andrea.buscema/Desktop/ap_exam/andrea/SIM2/project_sim2/build/CMakeFiles/FEModule.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FEModule.dir/depend

