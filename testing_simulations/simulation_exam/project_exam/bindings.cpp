#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "optimization_problem.h"
#include "gradient_descent.h"
#include "quadratic_optimization.h"
#include "linear_regression.h"

namespace py = pybind11;

PYBIND11_MODULE(Optimization_Solver, m) {
    py::class_<OptimizationProblem, std::shared_ptr<OptimizationProblem>>(m, "OptimizationProblem")
        .def("evaluate", &OptimizationProblem::evaluate)
        .def("evaluate_gradient", &OptimizationProblem::evaluate_gradient);

    py::class_<GradientDescent>(m, "GradientDescent")
        .def(py::init<const OptimizationProblem&, double, int, double>())
        .def("solve", &GradientDescent::solve);

    py::class_<QuadraticOptimizationProblem, std::shared_ptr<QuadraticOptimizationProblem>, OptimizationProblem>(m, "QuadraticOptimizationProblem")
        .def(py::init<>());

    py::class_<LinearRegressionProblem, std::shared_ptr<LinearRegressionProblem>, OptimizationProblem>(m, "LinearRegressionProblem")
        .def(py::init<const std::vector<double>&, const std::vector<double>&>());
}
