#ifndef QUADRATIC_OPTIMIZATION_PROBLEM_H
#define QUADRATIC_OPTIMIZATION_PROBLEM_H

#include "optimization_problem.h"
#include <vector>

class QuadraticOptimizationProblem : public OptimizationProblem {
public:
    // Implement objective function (f(x))
    double evaluate(const std::vector<double> &x) override {
        return (x[0] - 1) * (x[0] - 1); 
    }

    // Implement gradient calculation
    std::vector<double> evaluate_gradient(const std::vector<double> &x) override {
        return {2 * (x[0] - 1)}; 
    }
};

#endif