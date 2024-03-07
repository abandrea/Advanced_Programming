//Create specialized classes for different matrix types
// SquareMatrix,

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

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



class SquareMatrix : public Matrix {
    public:
        SquareMatrix();
        SquareMatrix(int size);
        SquareMatrix(const SquareMatrix& m);
        ~SquareMatrix();
        double determinant() const;
        SquareMatrix inverse() const;
        SquareMatrix submatrix(int row, int col) const;
        
};

SquareMatrix::SquareMatrix() {
    // constructor implementation
}

SquareMatrix::SquareMatrix(int size) {
    // constructor implementation
}

SquareMatrix::SquareMatrix(const SquareMatrix& m) {
    // constructor implementation
}

double SquareMatrix::determinant() const {
    // determinant implementation
    double det = 0;
    // calculate determinant
    return det;
}

SquareMatrix SquareMatrix::inverse() const {
    // inverse implementation
    SquareMatrix inv;
    // calculate inverse
    return inv;
}

SquareMatrix::~SquareMatrix() {
    // destructor implementation
}



#endif
