#Questo file conterrà tutte le istruzioni per CMake su 
#come compilare il progetto.

#CMake versione minima richiesta
cmake_minimum_required(VERSION 3.12)
project(project_sim2)

#Setta la versione di C++ a 17
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

#No need to manually set pybind11_dir if the environment variable is exported

find_package(pybind11 REQUIRED)

pybind11_add_module(project_sim2 pybind_sim2.cpp)


#Rimuovi Avviso di Cmake

#cmake_policy(SET CMP0148 NEW)
