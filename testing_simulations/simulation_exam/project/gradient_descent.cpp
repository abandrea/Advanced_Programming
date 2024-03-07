#include "optimization_problem.h" 
#include <iostream>
#include <vector>

class GradientDescent {
public:
    // Constructor 
    GradientDescent(OptimizationProblem& problem, double learning_rate = 0.1, 
                int max_iterations = 100, float tolerance = 1e-5) // Changed double to float
    : problem(problem), lr(learning_rate), max_iter(max_iterations), tol(tolerance) {}

    // Method to find the optimal solution 
    std::vector<double> optimize(std::vector<double> initial_x); 

private:
    OptimizationProblem& problem; // Reference to the problem being solved
    double lr;  // Learning rate
    int max_iter;   // Maximum number of iterations
    double tol;   // Tolerance for convergence
};

// Method to find the optimal solution

std::vector<double> GradientDescent::optimize(std::vector<double> initial_x) {
    double cost; // Cost function value
    int iter = 0; // Iteration counter

    do { // Gradient descent iterations
        std::vector<double> gradient = problem.evaluate_gradient(initial_x); // Compute gradient

        for (int i = 0; i < initial_x.size(); ++i) { // Update each variable
            initial_x[i] -= lr * gradient[i];  
        }

        cost = problem.evaluate(initial_x); // Compute cost
        iter++; 

        // implementation of logging (print iteration and cost to the console)
        std::cout << "Iteration: " << iter << ", Cost: " << cost << std::endl;

    } while (iter < max_iter && cost > tol); // Convergence check

    if (iter == max_iter) throw std::runtime_error("Convergence failed"); // Error message if the convergence fail

    return initial_x; // Return the optimal solution 
}

