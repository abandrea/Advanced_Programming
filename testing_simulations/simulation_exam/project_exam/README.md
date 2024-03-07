# Exam

## Objective

The objective of the exam it develop a Gradient Descent optimization algorithm using C++ and integrate it with Python using pybind11. The exercise will involve creating classes for describing a problem to be optimized and implementing the gradient descent algorithm.

## Mathematical background

### Gradient descent: general overview
Gradient Descent is a fundamental optimization algorithm used in machine learning and statistics to minimize an arbitrary function. It's an iterative approach for finding the minimum of a function, particularly useful when the function is complex and does not have a closed-form solution.

Given a scalar multi-variate function $f(\mathbf{z})$ to optimize, the method consists of the following iterative algorithm:

1. **Initialization**: Start with an initial guess for the parameters of the function to be optimized.
2. **Gradient calculation**: Compute the gradient of the function with respect to its parameters at the current point, i.e. $\nabla f(\mathbf{z})$.
3. **Update step**: Adjust each parameters in the opposite direction of the gradient, i.e. $z_{j, \text{new}} = z_j - \alpha \frac{\partial f}{\partial z_j}$. This step is governed by a parameter $\alpha$ known as the learning rate.
4. **Iteration**: Repeat steps 2 and 3 until $||f(\mathbf{z}_\text{new})||$ is below a certain threshold, or a maximum number of iterations is reached.
5. **Output**: The final parameter values are used as the solution, ideally representing the point where the function attains its minimum value.

### Gradient descent for linear regression
In the context of linear regression, Gradient Descent is used to find the parameters (coefficients) $\theta$ of the regression model that minimize a cost function, typically the Mean Squared Error (MSE).

Given a set of points $\lbrace(\mathbf{x}^{(i)}, y^{(i)})\rbrace_{i=0}^m$ with $x_0^{(i)} = 1$ $\forall i$, the linear regression model computes a prediction $\hat{y}^{(i)}$ of the output $y^{(i)}$ as a linear combination of the input features $\mathbf{x}^{(i)}$:

$$
\hat{y}^{(i)} = \theta_0 + \theta_1 x_1^{(i)} + \dots + \theta_n x_n^{(i)}.
$$

The MSE cost function for linear regression, to be minimized with respect to the vector $\theta$, is

$$
J(\theta) = \frac{1}{2m} \sum_{i=0}^{m} (\hat{y}^{(i)} - y^{(i)})^2.
$$

The gradient of the cost function is

$$
\frac{\partial J}{\partial \theta_j}(\theta) = \frac{1}{m} \sum_{i=0}^{m} \left[(\hat{y}^{(i)} - y^{(i)}) x_j^{(i)}\right].
$$

The final values of $\theta_0, \theta_1, \dots, \theta_n$ represent the best-fit parameters for the linear model.

---

## Tasks
The goal is to implement a Gradient Descent solver to solve the following two problems:

### Problem 1.
Minimize the scalar quadratic function $f(x)=(x-1)^2$. For such a function, a moderate learning rate, such as $\alpha = 0.1$, is typically a good starting point.

### Problem 2.
Generate a set of points $\lbrace(x^{(i)}, y^{(i)})\rbrace_{i=0}^m$ such that $y^{(i)} = 4 + \frac{1}{2} x^{(i)} + \epsilon$, where $\epsilon$ is a small random noise and minimize the model $\hat{y} = \theta_0 + \theta_1 x$. A smaller learning rate, such as $\alpha = 0.01$ or $\alpha = 0.001$, is often more appropriate for such problems, especially when the data is not normalized.

## Setting up environment
1. Install C++ Compiler: Ensure you have a C++ compiler like GCC or Clang.
2. Install Python: Verify Python installation on your system.
3. Once you have Python installed (version 3.12 or later), you create a virtual environment and install pybind11:
```bash
python3 -m venv env
source env/bin/activate
pip install pybind11
```
4. 

## Header
The header files are created to define the classes and methods that will be used in the C++ code. The header file is included in the source file to use the classes and methods defined in the header file.

## main
The main function is the entry point of the program. It is the function from where the execution of any C++ program begins. The main function is called by the operating system when the user runs the program.

## Explanation:

### Problem 1 (Quadratic Optimization):

* The `QuadraticOptimizationProblem` is instantiated for the function `f(x) = (x - 1)^2`.
* `GradientDescent` is used with an initial guess of `0` and a learning rate of `0.1`.

### Problem 2 (Linear Regression):

* Synthetic data is generated for `x_vals` and `y_vals` where `y(i) = 4 + 1x(i)^2 + \epsilon`, where the noise level is set to `0.1`.
* The `LinearRegressionProblem` is instantiated with this data.
* `GradientDescent` is used with initial guesses of `0` for both `theta0` and `theta1`, and a learning rate of `0.01`.

### Error Handling:

* Each problem is wrapped in a try-catch block to handle potential errors, such as non-convergence of the gradient descent algorithm.


