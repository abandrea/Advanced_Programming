#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include "optimization_problem.h"
#include <stdexcept>
#include <vector>

class GradientDescent {
    const OptimizationProblem &problem;
    double learningRate;
    int maxIterations;
    double convergenceThreshold;

public:
    GradientDescent(const OptimizationProblem &problem, double lr, int maxIter, double convThresh)
        : problem(problem), learningRate(lr), maxIterations(maxIter), convergenceThreshold(convThresh) {}

    std::pair<std::vector<double>, double> solve(const std::vector<double> &initial) const {
        std::vector<double> x = initial;
        double cost;
        for (int i = 0; i < maxIterations; ++i) {
            std::vector<double> gradient = problem.evaluate_gradient(x);
            for (size_t j = 0; j < x.size(); ++j) {
                x[j] -= learningRate * gradient[j];
            }
            cost = problem.evaluate(x);

            // Check convergence (simple implementation, can be more sophisticated)
            if (cost < convergenceThreshold) {
                return {x, cost};
            }
        }
        throw std::runtime_error("Gradient Descent failed to converge");
    }
};

#endif // GRADIENT_DESCENT_H
