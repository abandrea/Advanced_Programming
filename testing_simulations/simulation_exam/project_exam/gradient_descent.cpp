#include "gradient_descent.h"

#include <iostream>
#include <random>

namespace gd {
    // Function to find the minimum of a function using the gradient descent method
    double scalar_minimization(double alpha, int iterations) {
        double x = 0; // Initial guess
        for (int i=0; i < iterations; ++i) {
            x -= alpha*2*(x-1); // Derivative of the function
        };
        return x;
    }

    // Linear regression using the gradient descent method
    void linear_regression(double* x_vals, double* y_vals, 
            int m, double alpha, int iterations, double* theta) {
        // Initialize theta
        double theta0 = 0, theta1 = 0; 

        for (int i=0; i<iterations; ++i) {
            double sum0 = 0, sum1 = 0;

            for (int j=0; j<m; ++j) {
                double predictions = theta0 + theta1 * x_vals[j];
                sum0 += (predictions - y_vals[j]);
                sum1 += (predictions - y_vals[j]) * x_vals[j];
            }
        theta0 -= (alpha/m) * sum0;
        theta1 -= (alpha/m) * sum1;
        }
    theta[0] = theta0;
    theta[1] = theta1;
}
} // namespace gd

// int main() {
//     std::cout << "Scalar minimization: " << gd::scalar_minimization(0.1, 100) << std::endl;
//     double x[5] = {1, 2, 3, 4, 5};
//     double y[5] = {2, 3, 4, 5, 6};
//     double theta[2];
//     gd::linear_regression(x, y, 5, 0.1, 100, theta);
//     std::cout << "Linear regression: " << theta[0] << " " << theta[1] << std::endl;
//     return 0;
// }

//g++ -o main gradient_descent.cpp -std=c++17
//./main