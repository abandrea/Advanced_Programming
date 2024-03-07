#ifndef OPTIMIZATION_PROBLEM_H
#define OPTIMIZATION_PROBLEM_H

#include <vector>

class OptimizationProblem {
public:
    virtual ~OptimizationProblem() = default;

    virtual double evaluate(const std::vector<double> &input) const = 0;
    virtual std::vector<double> evaluate_gradient(const std::vector<double> &input) const = 0;
};

#endif // OPTIMIZATION_PROBLEM_H

