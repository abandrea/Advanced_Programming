#include "quadratic_optimization_problem.h"
#include "optimization_problem.h"
#include "gradient_descent.cpp" 
#include <iostream> 

int main() {
    // Create the optimization problem
    QuadraticOptimizationProblem problem; 

    // Create the gradient descent solver
    GradientDescent solver(problem, 0.1);  // Using a learning rate of 0.1

    // Specify an initial guess (starting point) 
    std::vector<double> initial_guess = {5.0}; // Example starting point

    // Run the optimization  
    std::vector<double> solution = solver.optimize(initial_guess);

    // Print the optimized solution
    std::cout << "Optimized solution: x = " << solution[0] << std::endl;

    return 0;
}

//g++ -o grad_test main.cpp -std=c++17
// ./grad_test

// Output:
// Iteration: 1, Cost: 10.24
// Iteration: 2, Cost: 6.5536
// Iteration: 3, Cost: 4.1943