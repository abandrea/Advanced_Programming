cmake_minimum_required(VERSION 3.4)
project(forward_euler_module)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the Python libraries and include pybind11
#find_package(PythonLibs REQUIRED)
find_package(pybind11 REQUIRED)

# Define the executable that includes the main function
add_executable(main main.cpp)

# Define the module that will be created using pybind11
pybind11_add_module(forward_euler_module bindings.cpp)

# Link the Python libraries to the module
target_link_libraries(forward_euler_module PRIVATE pybind11::pybind11)

# Include directories for the pybind11 headers and the Python headers
#target_include_directories(forward_euler_module PRIVATE ${PYTHON_INCLUDE_DIRS} ${pybind11_INCLUDE_DIR})


