#include <iostream>
#include <vector>
#include <random>
#include "gradient_descent.h"
#include "quadratic_optimization.h"
#include "linear_regression.h"

// Function to generate linear data with noise
std::vector<double> generate_y_vals(const std::vector<double>& x_vals, double intercept, double slope, double noiseLevel) {
    std::vector<double> y_vals;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> distr(0, noiseLevel);

    for (double x : x_vals) {
        double y = intercept + slope * x + distr(gen);
        y_vals.push_back(y);
    }

    return y_vals;
}

int main() {
    // Problem 1: Minimizing the scalar quadratic function f(x) = (x-1)^2
    QuadraticOptimizationProblem quadraticProblem;
    GradientDescent gdQuadratic(quadraticProblem, 0.1, 100, 1e-6);
    std::vector<double> initialGuessQuadratic = {0};  // Initial guess for x

    try {
        auto [solutionQuadratic, costQuadratic] = gdQuadratic.solve(initialGuessQuadratic);
        std::cout << "Problem 1 - Solution: x = " << solutionQuadratic[0] << ", Cost: " << costQuadratic << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Problem 1 - Error: " << e.what() << std::endl;
    }

    // Problem 2: Linear Regression with generated data points
    std::vector<double> x_vals(100);
    std::iota(x_vals.begin(), x_vals.end(), 0);  // Generating x values from 0 to 99
    std::vector<double> y_vals = generate_y_vals(x_vals, 4, 0.5, 0.1);  // y = 4 + 0.5x + noise

    LinearRegressionProblem linearProblem(x_vals, y_vals);
    GradientDescent gdLinear(linearProblem, 0.01, 1000, 1e-6);
    std::vector<double> initialGuessLinear = {0, 0};  // Initial guess for theta0, theta1

    try {
        auto [solutionLinear, costLinear] = gdLinear.solve(initialGuessLinear);
        std::cout << "Problem 2 - Solution: theta0 = " << solutionLinear[0] << ", theta1 = " << solutionLinear[1] 
                  << ", Cost: " << costLinear << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Problem 2 - Error: " << e.what() << std::endl;
    }

    return 0;
}


// g++ -o main main.cpp -std=c++17
// ./main