To compile, run the Compile.sh: it will create a virtual environment to install pybind11 in, then it
uses that to compile the source files. This is done in order to have the CMAKE always find the pybind11.

To run the Python test script, run the TestingEnvSetup.sh file: it will create a virtual environment with
the required packages. Activate it using

source TestEnv/bin/activate

then run the test_pe.py script. It will create 2 .png files containing plots of the results for the two and a file.txt with all numerical results.
implemented solvers. 
