#!/bin/bash

# Create a virtual environment
python3 -m venv compile

# Activate the virtual environment
source compile/bin/activate

# Install pybind11
pip install pybind11

# Extract pybind11 cmake directory and export it
PYBIND11_DIR=$(python -c "import pybind11; print(pybind11.get_cmake_dir())")
export pybind11_DIR=${PYBIND11_DIR}

# Create a build directory and move into it
mkdir -p build && cd build

# Run CMake and build the project
cmake ..
make

# Deactivate the virtual environment
deactivate
