#!/bin/bash

# Create a virtual environment named TestEnv
python3 -m venv TestEnv

# Activate the virtual environment
source TestEnv/bin/activate

# Install numpy and matplotlib
pip install numpy matplotlib

# Run your Python testing script
python3 test_pe.py

# Deactibvate the venv
deactivate
