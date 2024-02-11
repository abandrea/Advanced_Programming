#ifndef SPARSEMATRIXCOO_H
#define SPARSEMATRIXCOO_H

#include "SparseMatrixBase.h"
#include <vector>
#include <algorithm>
#include <iostream>


template <typename T>
class SparseMatrixCOO : public SparseMatrixBase<T> {
private:
    std::vector<T> values;     // Non-zero values
    std::vector<int> rows;     // Row indices of non-zero values
    std::vector<int> columns;  // Column indices of non-zero values
    int numRows, numCols;

public:
    SparseMatrixCOO(int numRows, int numCols) : numRows(numRows), numCols(numCols) {}

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
        auto it = std::find_if(values.begin(), values.end(),
                       [&, row, col](const T& val) {
                           int idx = &val - &values[0];
                           return rows[idx] == row && columns[idx] == col;}); // Check if the element exists
        if (it != values.end()) {
            return *it;
        } else {
            throw std::out_of_range("Element not found");
        }
        return static_cast<T>(0); // this is just to avoid compilation errors
    }

    void writeElement(int row, int col, T value) override {
        auto it = std::find_if(values.begin(), values.end(),
                       [&, row, col](const T& val) {
                           int idx = &val - &values[0]; // Calculate index
                           return rows[idx] == row && columns[idx] == col;}); // Check if the element exists
        if (it != values.end()) {
            *it = value;
        } else {
            // Optionally, handle the case for adding a new non-zero element
            values.push_back(value);
        }
    }

    std::vector<T> matrixVectorProduct(const std::vector<T>& vec) const override {
        std::vector<T> result(numRows, 0);
        for (size_t i = 0; i < values.size(); ++i) {
            result[rows[i]] += values[i] * vec[columns[i]];
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
        auto it = std::find_if(values.begin(), values.end(),
                       [&, row, col](const T& val) {
                           int idx = &val - &values[0];
                           return rows[idx] == row && columns[idx] == col;
                       }); // Check if the element exists
        if (it != values.end()) {
            int idx = it - values.begin();
            return values[idx];
        } else {
            throw std::out_of_range("Element not found");
        }
    }

    T& operator()(int row, int col) override {
        auto it = std::find_if(values.begin(), values.end(),
                       [&, row, col](const T& val) {
                           int idx = &val - &values[0];
                           return rows[idx] == row && columns[idx] == col;
                       }); // Check if the element exists
        if (it != values.end()) {
            int idx = it - values.begin();
            return values[idx];
        } else {
            // Add a new non-zero element with default value
            values.push_back(T());
            rows.push_back(row);
            columns.push_back(col);
            return values.back();
        }
    }

    std::vector<T> operator*(const std::vector<T>& vec) const override {
        return matrixVectorProduct(vec);
    }

    // Is it possible to add other utilities (optional)
    // ...
};

#endif // SPARSEMATRIXCOO_H