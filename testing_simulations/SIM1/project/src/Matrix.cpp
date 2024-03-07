#include "Matrix.h"

#include <stdexcept>
#include <iomanip> // Add include statement for <iomanip>


Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new double[rows * cols];
    // Inizializza tutti gli elementi a 0 o un valore di default
    std::fill_n(data, rows * cols, 0.0); // Inizializza tutti gli elementi a 0
}

Matrix::Matrix(const Matrix& other) {
    // Implementazione del costruttore di copia
    rows = other.rows;
    cols = other.cols;
    data = new double[rows * cols];
    std::copy(other.data, other.data + rows * cols, data);


}

Matrix::~Matrix() {
    // Destructor implementation

    delete[] data; // Dealloca la memoria

}

// Other method implementations...

int Matrix::getRows() const {
    // Method implementation
    return rows; // Restituisce il numero di righe
}

int Matrix::getCols() const {
    // Method implementation
    return cols; // Restituisce il numero di colonne
}

double Matrix::get(int i, int j) const {
    // Method implementation
    if (i <= 0 || i > rows || j <= 0 || j > cols) { // Controllo se i valori sono validi    
        throw std::out_of_range("Index out of range");
    }
    return data[(i-1) * cols + (j-1) ];  // Restituisce l'elemento in posizione i, j
}

void Matrix::set(int i, int j, double val) {
    // Method implementation
    if (i <= 0 || i > rows || j <= 0 || j > cols) {  // Controllo se i valori sono validi
        throw std::out_of_range("Index out of range");
    }
    data[(i-1) * cols + (j-1)] = val; // Imposta l'elemento in posizione i, j
}

void Matrix::print() const {
    // Method implementation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(10) << data[i * cols + j];
        }
        std::cout << std::endl; 
    } // Stampa la matrice
}



Matrix& Matrix::operator=(const Matrix& m) {
    // Operator implementation
    if (this != &m) {
        delete[] data;
        rows = m.rows;
        cols = m.cols;
        data = new double[rows * cols];
        std::copy(m.data, m.data + rows * cols, data);
    }
    return *this; // Restituisce l'oggetto corrente
}

double Matrix::determinant() const {
    if (rows != cols) {
        throw std::runtime_error("Matrix must be square to compute determinant");
    }

    if (rows == 1) {
        return data[0];
    }

    double det = 0.0;
    int sign = 1;
    for (int i = 0; i < cols; ++i) {
        Matrix sub = submatrix(0, i);
        det += sign * data[i] * sub.determinant();
        sign = -sign;
    }

    return det;
}

Matrix Matrix::transpose() const {
    // Method implementation
    Matrix transposed(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed.data[j * rows + i] = data[i * cols + j];
        }
    }
    return transposed;
}

Matrix Matrix::inverse() const {
    if (rows != cols) {
        throw std::runtime_error("Matrix must be square to compute inverse");
    }

    double det = determinant();
    if (det == 0.0) {
        throw std::runtime_error("Matrix is singular and cannot be inverted");
    }

    Matrix inv(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Calcola il cofattore
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            Matrix sub = submatrix(i, j);
            inv.data[j * rows + i] = sign * sub.determinant() / det;
        }
    }
    return inv;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            os << m.get(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m) {
    // Friend function implementation
    for (int i = 0; i < m.rows * m.cols; i++) {
        is >> m.data[i];
    }
    return is;
}

Matrix operator*(double scalar, const Matrix& m) {
    // Friend function implementation
    Matrix result(m.rows, m.cols);
    for (int i = 0; i < m.rows * m.cols; i++) {
        result.data[i] = scalar * m.data[i];
    }
    return result;
}

Matrix operator/(double scalar, const Matrix& m) {
    // Friend function implementation
    Matrix result(m.rows, m.cols);
    for (int i = 0; i < m.rows * m.cols; i++) {
        result.data[i] = m.data[i] / scalar;
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& m) const {
    // Operator implementation
    if (rows != m.rows || cols != m.cols) {
        throw std::invalid_argument("Matrices have different dimensions");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] - m.data[i];
    }
    return result;
}


Matrix Matrix::operator*(double scalar) const {
    // Operator implementation
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = scalar * data[i];
    }
    return result;
}

Matrix Matrix::operator/(double scalar) const {
    // Operator implementation
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] / scalar;
    }
    return result;
}
