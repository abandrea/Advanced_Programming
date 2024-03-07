#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include "ForwardEuler.h"
#include <pybind11/functional.h>


namespace py = pybind11;

PYBIND11_MODULE(project_sim2, m) {
    py::class_<ForwardEuler<1>>(m, "ForwardEuler1") // ForwardEuler1 è un'istanza di ForwardEuler per separare le due soluzioni
        .def(py::init<std::function<std::array<double, 1>(double, const std::array<double, 1>&)>>())
        .def("setInitialValue", &ForwardEuler<1>::setInitialValue)
        .def("solve", &ForwardEuler<1>::solve)
        .def("getSolution", &ForwardEuler<1>::getSolution);

    py::class_<ForwardEuler<2>>(m, "ForwardEuler2") // ForwardEuler2 è un'istanza di ForwardEuler per separare le due soluzioni
        .def(py::init<std::function<std::array<double, 2>(double, const std::array<double, 2>&)>>())
        .def("setInitialValue", &ForwardEuler<2>::setInitialValue)
        .def("solve", &ForwardEuler<2>::solve)
        .def("getSolution", &ForwardEuler<2>::getSolution);
}



