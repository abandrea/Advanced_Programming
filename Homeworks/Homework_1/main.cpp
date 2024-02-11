#include "SparseMatrixBase.h"
#include "SparseMatrixCOO.h"
#include "SparseMatrixCSR.h"
#include <iostream>
#include <vector>


int main() {
    // Example creation of SparseMatrixCOO and SparseMatrixCSR
    // constructors and necessary methods are already implemented
    // Assuming the matrices are already filled with some data
    // Create an instance of a derived class instead of the abstract class
    

    SparseMatrixCOO<double> matrixCOO(4, 5); // Example size
    //SparseMatrixCSR<double> matrixCSR(4, 5); // Example size

    //print matrix
    matrixCOO.printMatrix();
    //matrixCSR.printMatrix();


    // Test 1: Sum of each row
    // for (int i = 0; i < matrixCSR.getNumberOfRows(); ++i) {
    //     double sum = 0;
    //     for (int j = 0; j < matrixCSR.getNumberOfColumns(); ++j) {
    //         sum += matrixCSR.readElement(i, j);
    //     }
    //     std::cout << "Sum of row " << i << ": " << sum << std::endl;
    // }

    // Test 2: Multiplying with canonical basis vector
    // for (int i = 0; i < matrixCSR.getNumberOfColumns(); ++i) {
    //     std::vector<double> basisVector(matrixCSR.getNumberOfColumns(), 0);
    //     basisVector[i] = 1; // Creating the i-th canonical basis vector
    //     std::vector<double> column = matrixCSR.matrixVectorProduct(basisVector);
    //     std::cout << "Column " << i << ": ";
    //     for (auto val : column) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // Additional tests
    // Get the number of non-zero elements
    //std::cout << "Number of non-zero elements: " << matrixCSR.getNumberOfNonZeros() << std::endl;
    std::cout << "Number of non-zero elements: " << matrixCOO.getNumberOfNonZeros() << std::endl;
    // Read and write elements
    std::cout << "Read:\nElement at (0, 0): " << matrixCOO.readElement(0, 0) << std::endl;
    matrixCOO.writeElement(0, 0, 5);
    std::cout << "Write:\nElement at (0, 0): " << matrixCOO.readElement(0, 0) << std::endl;

    //Given a vector v, compute the product of the matrix with the vector
    std::vector<double> vec = {1, 2, 3, 4, 5};
    std::vector<double> result = matrixCSR.matrixVectorProduct(vec);
    std::cout << "Matrix-vector product: ";
    for (auto val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    //print the matrix in a human-readable format
    matrixCSR.printMatrix();




    return 0;
}


// compile with:
// g++ -std=c++17 -Wall -Wpedantic main.cpp -o sparse_matrix
// run with:
// ./sparse_matrix
// Expected output:

