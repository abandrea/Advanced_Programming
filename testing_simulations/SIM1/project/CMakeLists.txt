#Questo file conterrà tutte le istruzioni per CMake su come compilare il tuo progetto.

#CMake versione minima richiesta
cmake_minimum_required(VERSION 3.12)
project(MatrixLibrary)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

#Aggiungo la cartella con i file header
include_directories(include)

add_executable(matrix_app main.cpp src/Matrix.cpp)


#Rimuovi Avviso di Cmake

cmake_policy(SET CMP0148 NEW)

# Trova pybind11
find_package(pybind11 REQUIRED)

#Definizione del modulo python
pybind11_add_module(matrixlib bindings/pybind_module.cpp src/Matrix.cpp)
