cmake_minimum_required(VERSION 3.12)
project(Optimization_Solver)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the pybind11 module
find_package(pybind11 REQUIRED)

# Link the pybind11 module including bindings.cpp
pybind11_add_module(Optimization_Solver bindings.cpp main.cpp gradient_descent.cpp)

# Add the include directory (uncomment if you have an include directory)
# target_include_directories(gradient_solver PRIVATE include)

# Remove CMake Warning
cmake_policy(SET CMP0148 NEW)
