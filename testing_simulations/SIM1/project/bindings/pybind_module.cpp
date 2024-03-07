#include <pybind11/pybind11.h>
#include "Matrix.h"
#include "SquareMatrix.h"

namespace py = pybind11;

PYBIND11_MODULE(matrixlib, m) {
    m.doc() = "Matrix operations library"; // Documentazione opzionale

    py::class_<Matrix>(m, "Matrix")
        .def(py::init<int, int>())
        .def("set", &Matrix::set)
        .def("get", &Matrix::get)
        // Aggiungi altri metodi e proprietà necessari
        .def("submatrix", &Matrix::submatrix)
        .def("getRows", &Matrix::getRows)
        .def("getCols", &Matrix::getCols)
        .def("Inverse", &Matrix::inverse)
        .def("Determinant", &Matrix::determinant)
        .def("print", &Matrix::print)
        .def("operator=", &Matrix::operator=)
        .def("__str__", [](const Matrix &m) {
        std::stringstream stream;
        stream << m;
        return stream.str();
        })
        
        ;

}
