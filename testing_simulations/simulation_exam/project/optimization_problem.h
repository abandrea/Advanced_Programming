#ifndef OPTIMIZATION_PROBLEM_H
#define OPTIMIZATION_PROBLEM_H

#include <vector>

class OptimizationProblem {
public:
    // Pure virtual method for evaluating the objective function
    virtual double evaluate(const std::vector<double> &input) = 0;

    // Pure virtual method for calculating the gradient 
    virtual std::vector<double> evaluate_gradient(const std::vector<double> &input) = 0;

    // Virtual destructor
    virtual ~OptimizationProblem() = default;

};

#endif