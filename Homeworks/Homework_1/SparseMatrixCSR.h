#include "SparseMatrixBase.h"
#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class SparseMatrixCSR : public SparseMatrixBase<T> // Inherit from the base class
{
private:
    std::vector<T> values;     // Non-zero values
    std::vector<int> columns;  // Column indices of non-zero values
    std::vector<int> row_idx;  // Cumulative number of non-zero entries up to each row
    int numRows, numCols;

public:
    SparseMatrixCSR(int numRows, int numCols) : numRows(numRows), numCols(numCols) {
        row_idx.resize(numRows + 1, 0); // By convention, row_idx starts with 0
    }

    int getNumberOfRows() const override {
        return numRows;
    }

    int getNumberOfColumns() const override {
        return numCols;
    }

    int getNumberOfNonZeros() const override {
        return static_cast<int>(values.size());
    }

    T readElement(int row, int col) const override {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) { // Check if the indices are within bounds
            throw std::out_of_range("Indices are out of bounds");
        }
        for (int i = row_idx[row]; i < row_idx[row + 1]; ++i) {
            if (columns[i] == col) {
                return values[i];
            }
        }
        return static_cast<T>(0); // Return zero for non-existent elements
    }

    // void writeElement(int row, int col, T value) override {
    //     // Implementation here, consider handling new non-zero values
    // } // not implemented 

    std::vector<T> matrixVectorProduct(const std::vector<T>& vec) const override {
        if (vec.size() != static_cast<size_t>(numCols)) { // Check if the vector size matches the number of columns
            throw std::invalid_argument("Vector size must match the number of columns");
        }
        std::vector<T> result(numRows, 0);
        for (int i = 0; i < numRows; ++i) {
            for (int j = row_idx[i]; j < row_idx[i + 1]; ++j) {
                result[i] += values[j] * vec[columns[j]];
            }
        }
        return result;
    }

    void printMatrix() const override {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                std::cout << readElement(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    // Operator overloading
    T operator()(int row, int col) const override {
        return readElement(row, col);
    }

    // T& operator()(int row, int col) override {
    //     // Implementation here for write access
    // } // non implemented 

    std::vector<T> operator*(const std::vector<T>& vec) const override {
        return matrixVectorProduct(vec);
    }

    // Additional utilities (optional)
    // ...
};
