#This file contain the instructions to build the project

cmake_minimum_required(VERSION 3.12)  
project(gradient_descent_project)

#Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find the python package
find_package(pybind11 REQUIRED)

# Add the executable
pybind11_add_module(gradient_descent pybind_module.cpp) 

# Link your application (gradient_descent_app) against the Python module
#target_link_libraries(gradient_descent_app PRIVATE gradient_descent) 



