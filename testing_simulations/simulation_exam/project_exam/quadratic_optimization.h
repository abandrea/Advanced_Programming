#ifndef QUADRATIC_OPTIMIZATION_PROBLEM_H
#define QUADRATIC_OPTIMIZATION_PROBLEM_H

#include "optimization_problem.h"

class QuadraticOptimizationProblem : public OptimizationProblem {
public:
    double evaluate(const std::vector<double> &input) const override {
        // Assuming input[0] is 'x' for f(x) = (x-1)^2
        double x = input[0];
        return (x - 1) * (x - 1);
    }

    std::vector<double> evaluate_gradient(const std::vector<double> &input) const override {
        double x = input[0];
        return {2 * (x - 1)};
    }
};

#endif // QUADRATIC_OPTIMIZATION_PROBLEM_H
