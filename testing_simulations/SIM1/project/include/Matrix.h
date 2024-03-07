//Create an advanced C++ library for matrix operations 
//(like matrix multiplication, inversion, and determinant calculation) 
//using object-oriented and generic programming paradigms.

//Design a base 'Matrix' class with common attributes
// and methods for all matrix types. 

#ifndef MATRIX_H
#define MATRIX_H


//required libraries
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
#include <functional>
#include <iterator>
#include <memory>

//Matrix class


class Matrix { //base class
    private:
    //     Matrix submatrix(int row, int col) const {
    //     Matrix sub(rows - 1, cols - 1);
    //     int subi = 0;
    //     for (int i = 0; i < rows; i++) {
    //         if (i == row) continue;
    //         int subj = 0;
    //         for (int j = 0; j < cols; j++) {
    //             if (j == col) continue;
    //             sub.data[subi * sub.cols + subj] = data[i * cols + j];
    //             subj++;
    //         }
    //         subi++;
    //     }
    //     return sub;
    // }

    protected:
        int rows;
        int cols;
        double* data;
    public:
    //Constructors
        Matrix() {} //default constructor
        Matrix(int rows, int cols); //constructor with rows and cols
        Matrix(const Matrix& m); //copy constructor
        ~Matrix(); //destructor
        Matrix submatrix(int row, int col) const{
        Matrix sub(rows - 1, cols - 1);
        int subi = 0;
        for (int i = 0; i < rows; i++) {
            if (i == row) continue;
            int subj = 0;
            for (int j = 0; j < cols; j++) {
                if (j == col) continue;
                sub.data[subi * sub.cols + subj] = data[i * cols + j];
                subj++;
            }
            subi++;
        }
        return sub;
    }; //submatrix
    
    //Methods
        int getRows() const; //get number of rows
        int getCols() const; //get number of columns
        double get(int i, int j) const; //get element at position i, j
        void set(int i, int j, double val); //set element at position i, j
        void print() const; //print the matrix
    //Operators
        Matrix& operator=(const Matrix& m); //assignment operator
        Matrix operator+(const Matrix& m) const; //addition operator
        Matrix operator-(const Matrix& m) const; //subtraction operator
        Matrix operator*(const Matrix& m) const; //multiplication operator
        Matrix operator*(double scalar) const; //multiplication by scalar
        Matrix operator/(double scalar) const; //division by scalar
        bool operator==(const Matrix& m) const; //equality operator
        bool operator!=(const Matrix& m) const; //inequality operator
        Matrix operator-() const; //negation
        Matrix operator+() const; //unary plus
    //inversion
        Matrix inverse() const; //inverse
    //determinant
        double determinant() const; //determinant
    //transpose
        Matrix transpose() const; //transpose
    
    //friend functions
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m); //output operator
        friend std::istream& operator>>(std::istream& is, Matrix& m); //input operator
        friend Matrix operator*(double scalar, const Matrix& m); //multiplication by scalar
        friend Matrix operator/(double scalar, const Matrix& m); //division by scalar

        

};


#endif



