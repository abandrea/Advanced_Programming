Build a programming project, that will be executable by other computer. The project will be an library in C++ that works in python scripts (using pybind11). So, first of all it's important organise files and submitted as single file zip archive containing only source code files, documentation and any other relevant information such README.md with a brief explanation of the code structure and instructions for building and running the code.

The goal is to implement a Gradient Descent solver to solve the following two problems:

Problem 1.
Minimize the scalar quadratic function $f(x)=(x-1)^2$. For such a function, a moderate learning rate, such as $\alpha = 0.1$, is typically a good starting point.

Problem 2.
Generate a set of points $\lbrace(x^{(i)}, y^{(i)})\rbrace_{i=0}^m$ such that $y^{(i)} = 4 + \frac{1}{2} x^{(i)} + \epsilon$, where $\epsilon$ is a small random noise and minimize the model $\hat{y} = \theta_0 + \theta_1 x$. A smaller learning rate, such as $\alpha = 0.01$ or $\alpha = 0.001$, is often more appropriate for such problems, especially when the data is not normalized.


/Users/andrea.buscema/Desktop/adv_prog/EXAM/project_exam/env/lib/python3.12/site-packages/pybind11

EXAM/project_exam/env/lib/python3.12/site-packages/pybind11/include/pybind11/pybind11.h



cmake_minimum_required(VERSION 3.12) 
project(YourProjectName) 


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(pybind11 REQUIRED)

#include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})
include_directories(include)

add_executable(main_executable src/main.cpp src/grad.cpp)


pybind11_add_module(gradient_module bind/bind.cpp src/grad.cpp)

