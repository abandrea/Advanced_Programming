import Optimization_Solver #import the module created
import random


# For Problem 1
quadratic_problem = Optimization_Solver.QuadraticOptimizationProblem()
gd_quadratic = Optimization_Solver.GradientDescent(quadratic_problem, 0.1, 100, 1e-6)
solution_quadratic, cost_quadratic = gd_quadratic.solve([0])
print(f"Solution for quadratic problem: {solution_quadratic}, Cost: {cost_quadratic}")

# Problem 2: Linear Regression
x_vals = [i for i in range(100)]  
y_vals = [4 + 0.5 * x + random.gauss(0, 0.1) for x in x_vals] 
linear_problem = Optimization_Solver.LinearRegressionProblem(x_vals, y_vals)
#gd_linear = Optimization_Solver.GradientDescent(linear_problem, 0.1, 10000, 1e-6)  # Default parameters
gd_linear = Optimization_Solver.GradientDescent(linear_problem, 0.05, 200, 0.1)  # Adjusted parameters
#initial_guess = [0, 0]  # Default initial guess
initial_guess = [1, 1]  # Different initial guess

try:
    solution_linear, cost_linear = gd_linear.solve(initial_guess)
    print(f"Solution for linear regression problem: {solution_linear}, Cost: {cost_linear}")
except RuntimeError as e:
    print(f"Problem 2 - Error: {e}")