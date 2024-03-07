//DiagonalMatrix.cpp

#include "DiagonalMatrix.h"
#include "Matrix.h"
#include <stdexcept>
#include <iomanip> // Add include statement for <iomanip>

DiagonalMatrix::DiagonalMatrix() : DiagonalMatrix() {
    // Costruttore di default
}

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& m) : DiagonalMatrix(m) {
    // Costruttore di copia
}

DiagonalMatrix::~DiagonalMatrix() {
    // Distruttore
    // Nessuna gestione speciale della memoria necessaria
}

double DiagonalMatrix::determinant() const {
    double det = 1;
    for (int i = 0; i < getRows(); i++) {
        det *= get(i, i);
    }
    return det;
}

DiagonalMatrix DiagonalMatrix::inverse() const {
    int n = getRows();
    DiagonalMatrix inv(n);
    for (int i = 0; i < n; i++) {
        double diagElement = get(i, i);
        if (diagElement == 0) {
            throw std::runtime_error("Matrix is not invertible");
        }
        inv.set(i, i, 1.0 / diagElement);
    }
    return inv;
}
