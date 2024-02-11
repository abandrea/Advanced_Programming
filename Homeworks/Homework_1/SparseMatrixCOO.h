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
            [&](const auto& val, int idx) { return rows[idx] == row && columns[idx] == col; });
        if (it != values.end()) {
            return *it;
        } else {
            throw std::out_of_range("Element not found");
        }
    }

    void writeElement(int row, int col, T value) override {
        auto it = std::find_if(values.begin(), values.end(),
            [&](const auto& val, int idx) { return rows[idx] == row && columns[idx] == col; });
        if (it != values.end()) {
            *it = value;
        } else {
            // Optionally, handle the case for adding a new non-zero element
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
        return readElement(row, col);
    }

    T& operator()(int row, int col) override {
        // Implement write access via this operator
    }

    std::vector<T> operator*(const std::vector<T>& vec) const override {
        return matrixVectorProduct(vec);
    }

    // Is it possible to add other utilities (optional)
    // ...
};
