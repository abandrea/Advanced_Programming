// SquareMatrix.cpp
#include "SquareMatrix.h"
#include <cmath>
#include <stdexcept>
#include <iomanip> // Add include statement for <iomanip>
#include "Matrix.h"

SquareMatrix::SquareMatrix() : Matrix() {
    // Default constructor implementation
}

SquareMatrix::SquareMatrix(int size) : Matrix(size, size) {
    // Inizializza una matrice identità
    for (int i = 0; i < size; i++) {
        set(i, i, 1);
    }
}

SquareMatrix SquareMatrix::submatrix(int row, int col) const {
    int subSize = rows - 1;
    SquareMatrix sub(subSize);
    int subRow = 0;
    int subCol = 0;
    for (int i = 0; i < rows; i++) {
        if (i != row) {
            subCol = 0;
            for (int j = 0; j < cols; j++) {
                if (j != col) {
                    sub.set(subRow, subCol, get(i, j));
                    subCol++;
                }
            }
            subRow++;
        }
    }
    return sub;
}

double SquareMatrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square");
    }
    if (rows == 1) {
        return get(0, 0);
    }
    double det = 0;
    for (int i = 0; i < rows; i++) {
        double sign = (i % 2 == 0) ? 1 : -1;
        SquareMatrix sub = submatrix(0, i);
        det += sign * get(0, i) * sub.determinant();
    }
    return det;
}

SquareMatrix SquareMatrix::inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square");
    }
    double det = determinant();
    if (det == 0) {
        throw std::invalid_argument("Matrix is singular");
    }
    SquareMatrix inv(rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double sign = ((i + j) % 2 == 0) ? 1 : -1;
            SquareMatrix sub = submatrix(i, j);
            inv.set(j, i, sign * sub.determinant() / det);
        }
    }
    return inv;
}
