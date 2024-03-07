//Create specialized classes for different matrix types
// DiagonalMatrix 

//eredita da SquareMatrix.h e implementa le funzioni specifiche per le matrici diagonali

#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

//required libraries
#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <numeric>

//DiagonalMatrix class



class DiagonalMatrix : public Matrix {
    public:
        DiagonalMatrix();
        DiagonalMatrix(int size);
        DiagonalMatrix(const DiagonalMatrix& m);
        ~DiagonalMatrix();
        double determinant() const;
        DiagonalMatrix inverse() const;
};

DiagonalMatrix::DiagonalMatrix() {
    // constructor implementation
}

DiagonalMatrix::DiagonalMatrix(int size) {
    // constructor implementation
}

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& m) {
    // constructor implementation
}

double DiagonalMatrix::determinant() const {
    // determinant implementation
    double det = 0;
    // calculate determinant
    return det;
}

DiagonalMatrix DiagonalMatrix::inverse() const {
    // inverse implementation
    DiagonalMatrix inv;
    // calculate inverse
    return inv;
}

DiagonalMatrix::~DiagonalMatrix() {
    // destructor implementation
}



#endif
