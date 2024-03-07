# Part 1: Open-ended questions

## Question 1
What is a preprocessor and what is it used for?<br>
Given a C++ source file `code.cpp`, which shell command can be used to export the output of the preprocessor to a file `code_preprocessed.cpp`?

## Answer
A preprocessor is a program that processes its input data to produce output that is used as input to another program. In C and C++ programming, the preprocessor handles directives like #include, #define, and #if. These directives allow the programmer to include libraries, define macros, and conditionally include code, respectively.

The shell command to preprocess a C++ file and output the result to another file using the GCC compiler is:

```shell
g++ -E code.cpp -o code_prepocessed.cpp 
```
-E tells the compiler to stop after the preprocessing stage, and -o specifies the output file.


---

## Question 2
Describe what is meant by *undefined behavior* in C++.<br>
Give examples of common programming mistake in C++ that can lead to undefined behavior.

## Answer
Undefined behavior in C++ refers to the behavior of a program that is not defined by the C++ standard. This means that the compiler is free to interpret the code in any way it sees fit, and the program may behave differently on different platforms or with different compilers. Undefined behavior can lead to crashes, security vulnerabilities, and other unexpected behavior.

Some common programming mistakes that can lead to undefined behavior include:
- Dereferencing a null pointer
- Reading from or writing to an array out of bounds
- Using an uninitialized variable
- Modifying a variable more than once between sequence points
- Using the value of a variable after it has been destroyed



---

## Question 3
Compare and contrast `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.<br>
When should each be used? Provide some prototypical examples of use.

## Answer

/ The `std::unique_ptr` is a smart pointer that owns and manages another object through a pointer and disposes of that object when the `std::unique_ptr` goes out of scope. It is the only smart pointer that can manage a raw pointer without sharing ownership. It is useful when you want to transfer ownership of a dynamically allocated object to a function or when you want to ensure that an object is deleted when it is no longer needed.

```cpp
std::unique_ptr<int> p1(new int(5));
std::unique_ptr<int> p2 = std::move(p1);
```

The `std::shared_ptr` is a smart pointer that retains shared ownership of an object through a pointer. It allows multiple `std::shared_ptr` objects to share ownership of the same object. The object is deleted when the last `std::shared_ptr` that owns it is destroyed. It is useful when you want to share ownership of an object between multiple parts of a program or when you want to create a reference-counted object.

```cpp
std::shared_ptr<int> p1(new int(5));
std::shared_ptr<int> p2 = p1;
```

The `std::weak_ptr` is a smart pointer that provides a non-owning "weak" reference to an object that is managed by a `std::shared_ptr`. It is useful when you want to avoid creating reference cycles between `std::shared_ptr` objects or when you want to avoid the overhead of reference counting.

```cpp
std::shared_ptr<int> p1(new int(5));
std::weak_ptr<int> p2 = p1;
```



---

## Question 4
What's the difference between *Aggregation* and *Inheritance* in object-oriented programming?<br>
Provide some conceptual example for each of the two types of relationship.

## Answer

/ In object-oriented programming, aggregation and inheritance are two types of relationships between classes.
/ Aggregation is a "has-a" relationship, where one class contains another class as a member
/ Inheritance is an "is-a" relationship, where one class is derived from another class

An example of aggregation is a car and an engine. The car class contains an engine object as a member, and the engine object can exist independently of the car object.

```cpp
class Engine {
    // ...
};

class Car {
    Engine engine;
    // ...
};
```


---

## Question 5
Explain the concept of dynamic memory management in C++.<br>
Discuss the differences between `new`/`delete` and `malloc`/`free`. Which scenarios are appropriate for each?

## Answer

/ Dynamic memory management in C++ refers to the allocation and deallocation of memory at runtime. This allows the programmer to create and destroy objects as needed, rather than having to allocate all memory at the beginning of the program.

/ The `new` and `delete` operators are used to allocate and deallocate memory for objects in C++. They are type-safe and automatically call the constructor and destructor of the object, respectively.

```cpp
int* p = new int(5);
delete p;
```

/ The `malloc` and `free` functions are used to allocate and deallocate memory for raw data in C. They are not type-safe and do not call the constructor and destructor of the object, so they are not suitable for use with C++ objects.

```cpp
int* p = (int*)malloc(sizeof(int));
free(p);
```

/ The `new` and `delete` operators are appropriate for use with C++ objects, while `malloc` and `free` are appropriate for use with raw data in C.



---

## Question 6
What are lambda functions in C++ and Python?<br>
How do they differ between the two languages and how are they used?

## Answer

/ Lambda functions in C++ and Python are anonymous functions that can be defined inline and used as arguments to other functions.

/ In C++, a lambda function is defined using the following syntax:

```cpp
[] (int x, int y) { return x + y; }
```

/ In Python, a lambda function is defined using the following syntax:

```python
lambda x, y: x + y
```

/ The main difference between lambda functions in C++ and Python is that lambda functions in C++ can capture variables from the surrounding scope, while lambda functions in Python cannot.


---

## Question 7
What are the advantages of using NumPy arrays over standard Python lists for scientific computing?<br>
Demonstrate with an example how to perform element-wise operations on NumPy arrays.

## Answer

/ NumPy arrays are more efficient than standard Python lists for scientific computing because they are implemented in C and have a fixed size, which allows for faster element access and manipulation.

/ NumPy arrays also support vectorized operations, which allow you to perform element-wise operations on arrays without having to write explicit loops.

```python
import numpy as np

a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

c = a + b
```




---

## Question 8
Discuss the capabilities of the Matplotlib library in Python.<br>
Provide an example of how to create a line plot and a scatter plot using Matplotlib.

## Answer

/ Matplotlib is a plotting library for Python that provides a wide variety of plotting functions and customization options.

/ Matplotlib can be used to create line plots, scatter plots, bar plots, histograms, and many other types of plots.

```python
import matplotlib.pyplot as plt

# Line plot
x = [1, 2, 3, 4, 5]
y = [1, 4, 9, 16, 25]
plt.plot(x, y)
plt.show()  # Display the plot

# Scatter plot
x = [1, 2, 3, 4, 5]
y = [1, 4, 9, 16, 25]
plt.scatter(x, y)
plt.show()  # Display the plot
```


---

## Question 9
What are list comprehensions in Python and how do they work?<br>
Rewrite a for loop that filters and transforms a list into an equivalent list comprehension.

## Answer

/ List comprehensions in Python are a concise way to create lists by transforming and filtering other lists.

/ A list comprehension consists of an expression followed by a for clause, then zero or more for or if clauses.

```python
# For loop
numbers = [1, 2, 3, 4, 5]
squares = []
for n in numbers:
    if n % 2 == 0:
        squares.append(n**2)

# List comprehension
squares = [n**2 for n in numbers if n % 2 == 0]
```

The list comprehension is equivalent to the for loop and produces the same result.


---

## Question 10
How does pybind11 handle type conversions between Python and C++?<br>
Provide an example of passing complex data types (like a list or a dictionary) from Python to C++ using pybind11.

## Answer

/ pybind11 is a lightweight header-only library that exposes C++ types and functions to Python and vice versa.

/ pybind11 handles type conversions between Python and C++ by providing a simple and intuitive interface for defining bindings between the two languages.

```cpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

int sum_list(const std::vector<int>& list) {
    int sum = 0;
    for (int x : list) {
        sum += x;
    }
    return sum;
}

PYBIND11_MODULE(example, m) {
    m.def("sum_list", &sum_list);
}
```

```python
import example

numbers = [1, 2, 3, 4, 5]
total = example.sum_list(numbers)
print(total)
```

In this example, the `sum_list` function takes a `std::vector<int>` as an argument and returns the sum of the elements. The `PYBIND11_MODULE` macro is used to define the bindings between the C++ code and Python.


