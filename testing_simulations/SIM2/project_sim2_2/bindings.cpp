#include "forward_euler.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
//#include <pybind11/embed.h> // Add this line to include the necessary header file


// #include "helloworld.h"

namespace py = pybind11;

// PYBIND11_MODULE(helloworld_module, m) {
//     m.doc() = "Hello World Module";
//     py::class_<HelloWorld>(m, "HelloWorld")
//         .def(py::init<>())
//         .def("cout_hello_world", &HelloWorld::cout_hello_world);
// }

PYBIND11_MODULE(forward_euler_module, m) {
    m.doc() = "Forward Euler ODE Solver Module";
    
    //Bind the ForwardEuler class
    py::class_<ForwardEuler<2>>(m, "ForwardEuler")
        .def(py::init<std::array<double, 2>, double, double, double, std::function<std::array<double, 2>(double, std::array<double, 2>)>>())
        .def("solve", &ForwardEuler<2>::solve)
        .def("get_solution", &ForwardEuler<2>::get_solution);
}

