#include "forward_euler.h"
#include <iostream>
#include <fstream>

int main() {
    // Parameters for the Lotka-Volterra equations
    double alpha = 0.1;  // Prey birth rate
    double beta = 0.02;  // Predation rate
    double gamma = 0.3;  // Predator death rate
    double delta = 0.01; // Predator reproduction rate

    // Initial values
    std::array<double, 2> initial_values = {40, 9}; // x0 = 40 (prey), y0 = 9 (predators)

    // Time parameters
    double t0 = 0;       // Initial time
    double tf = 200;     // Final time
    double dt = 0.05;    // Timestep

    // Lotka-Volterra system as a lambda function
    auto lotka_volterra_system = [alpha, beta, gamma, delta](double, std::array<double, 2> values) {
        std::array<double, 2> derivatives;
        derivatives[0] = alpha * values[0] - beta * values[0] * values[1]; // dx/dt = alpha*x - beta*x*y
        derivatives[1] = delta * values[0] * values[1] - gamma * values[1]; // dy/dt = delta*x*y - gamma*y
        return derivatives;
    };

    // Create an instance of ForwardEuler
    ForwardEuler<2> solve(initial_values, t0, tf, dt, lotka_volterra_system);

    // Solve the system
    solve.solve();

    // Retrieve and print the solution and create a file with the solution 
    // const auto& solution = solve.get_solution();
    // std::ofstream output_file("lotka_volterra_solution.csv");
    // for (const auto& values : solution) {
    //     std::cout << "Prey: " << values[0] << ", Predators: " << values[1] << std::endl;
    //     output_file << values[0] << ',' << values[1] << '\n';
    
    //Retrive, don't print but create a file csv with the solution
    const auto& solution = solve.get_solution();
    std::ofstream output_file("lotka_volterra_results.csv");
    for (const auto& values : solution) {
        output_file << "Prey: " << values[0] << ", Predators: " << values[1] << "\n";
    }
    
    return 0;
}

//g++ -o main main.cpp -std=c++17
