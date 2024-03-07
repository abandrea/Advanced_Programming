import gradient_descent 
import numpy as np

# Create a QuadraticOptimizationProblem
problem = gradient_descent.QuadraticOptimizationProblem()

# Create a GradientDescent solver instance
solver = gradient_descent.GradientDescent(problem, 0.1, 100, 0.00001) 

#Test the exception handling
# solver = gradient_descent.GradientDescent(problem, 0.4, 1000, 0.4) 

# Set an initial guess 
initial_x = np.array([5.0])

# Run the optimization  
#solution = solver.optimize(initial_x)

# Print the optimized solution with exception handling
try:
    solution = solver.optimize(initial_x)
    print("Optimized solution:", solution)
except RuntimeError as err:
    print("Optimization Error:", err) 


#print("Optimized solution: x =", solution[0])

# Validate the solution
def validate_problem1_solution(computed_solution, desired_accuracy=1e-2):
    # """
    # Validates the computed solution for Problem 1 against the exact solution (x = 1).

    # Args:
    #     computed_solution (float or np.ndarray): The solution obtained by the solver.
    #     desired_accuracy (float, optional):  Maximum allowed error tolerance. Defaults to 1e-6.

    # Raises:
    #     AssertionError: If the error between the computed and exact solution exceeds the tolerance.
    # """

    exact_solution = 1.0

    # Calculate the error with respect to the exact solution
    error = np.abs(computed_solution - exact_solution)

    # Ensure the error is within the desired accuracy
    assert error <= desired_accuracy, f"Solution error ({error}) exceeds tolerance ({desired_accuracy})" 


solution = solver.optimize(initial_x)

# Print the optimized solution
print("Optimized solution: x =", solution[0])

# Validate the solution for Problem 1 
validate_problem1_solution(solution[0]) 
print("Solution validation passed!")  # Prints  if  no AssertionError is raised