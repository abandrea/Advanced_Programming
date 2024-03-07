#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  

#include "optimization_problem.h"
#include "quadratic_optimization_problem.h"
#include "gradient_descent.cpp"

namespace py = pybind11;

PYBIND11_MODULE(gradient_descent, m) {
    //  Bind the OptimizationProblem class (likely just for demonstration)
    py::class_<OptimizationProblem>(m, "OptimizationProblem")
        .def("evaluate", &OptimizationProblem::evaluate)
        .def("evaluate_gradient", &OptimizationProblem::evaluate_gradient);

    //  Bind the QuadraticOptimizationProblem class 

    py::class_<QuadraticOptimizationProblem, OptimizationProblem>(m, "QuadraticOptimizationProblem")
        .def(py::init<>())
        .def("evaluate", &QuadraticOptimizationProblem::evaluate)
        .def("evaluate_gradient", &QuadraticOptimizationProblem::evaluate_gradient);
    
     //  Bind the GradientDescent class
    py::class_<GradientDescent>(m, "GradientDescent")
    .def(py::init<OptimizationProblem&, double, int, float>())
    .def("optimize", &GradientDescent::optimize, 
         "Performs gradient descent optimization.",
         py::arg("initial_x"));
}




