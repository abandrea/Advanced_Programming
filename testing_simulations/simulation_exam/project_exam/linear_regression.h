#ifndef LINEAR_REGRESSION_PROBLEM_H
#define LINEAR_REGRESSION_PROBLEM_H

#include "optimization_problem.h"
#include <vector>

class LinearRegressionProblem : public OptimizationProblem {
    std::vector<double> x_vals;
    std::vector<double> y_vals;

public:
    // Constructor: Initializes the problem with data points
    LinearRegressionProblem(const std::vector<double> &x, const std::vector<double> &y) : x_vals(x), y_vals(y) {}

    // Evaluates the cost function for linear regression
    double evaluate(const std::vector<double> &theta) const override {
        double cost = 0.0;
        for (size_t i = 0; i < x_vals.size(); ++i) {
            double prediction = theta[0] + theta[1] * x_vals[i];  // Linear model: y = theta0 + theta1 * x
            cost += (prediction - y_vals[i]) * (prediction - y_vals[i]);
        }
        return cost / (2 * x_vals.size());  // Mean Squared Error
    }

    // Evaluates the gradient of the cost function for linear regression
    std::vector<double> evaluate_gradient(const std::vector<double> &theta) const override {
        double sum0 = 0, sum1 = 0;
        for (size_t i = 0; i < x_vals.size(); ++i) {
            double prediction = theta[0] + theta[1] * x_vals[i];
            sum0 += (prediction - y_vals[i]);                  // Derivative w.r.t. theta0
            sum1 += (prediction - y_vals[i]) * x_vals[i];      // Derivative w.r.t. theta1
        }
        size_t m = x_vals.size();
        return {sum0 / m, sum1 / m};  // Gradient vector
    }
};

#endif // LINEAR_REGRESSION_PROBLEM_H
