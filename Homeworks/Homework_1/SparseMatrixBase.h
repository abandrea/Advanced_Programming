#ifndef SPARSEMATRIXBASE_H
#define SPARSEMATRIXBASE_H


#include <vector>
#include <iostream>


template <typename T>
class SparseMatrixBase {
public:
    // virtual is used to allow derived classes to override the base class implementation
    virtual ~SparseMatrixBase() {}

    // Public interface for the SparseMatrixBase class
    virtual int getNumberOfRows() const = 0;
    virtual int getNumberOfColumns() const = 0;
    virtual int getNumberOfNonZeros() const = 0;
    virtual T readElement(int row, int col) const = 0;
    virtual void writeElement(int row, int col, T value) = 0;
    virtual std::vector<T> matrixVectorProduct(const std::vector<T>& vec) const = 0;
    virtual void printMatrix() const = 0;

    // Operator overloading (if necessary)
    virtual T operator()(int row, int col) const = 0;
    virtual T& operator()(int row, int col) = 0;
    virtual std::vector<T> operator*(const std::vector<T>& vec) const = 0;

    // Additional utilities (optional)
    // at the moment, we don't need any additional utilities
};

#endif // SPARSEMATRIXBASE_H