#ifndef FORWARD_EULER_H
#define FORWARD_EULER_H

#include <array>
#include <vector>
#include <functional>

template<size_t n>
class ForwardEuler {
public:
    // Constructor
    ForwardEuler(
        std::array<double, n> initial_value,
        double t0,
        double tf,
        double dt,
        std::function<std::array<double, n>(double, std::array<double, n>)> ode_system):
        initial_value_(initial_value), t0_(t0), tf_(tf), dt_(dt), ode_system_(ode_system) {
        current_value_ = initial_value_;
        solution_.push_back(current_value_);
        };

    // Method to execute the solver
    void solve() {
        double t = t0_;
        while (t<tf_) {
            //calculate the derivative using ODE system
            std::array<double,n> derivative = ode_system_(t, current_value_);
            // forward euler step for each element of the state vector
            for (size_t i=0; i<n; i++) {
                current_value_[i] += dt_ * derivative[i]; // x(t+dt) = x(t) + dt * f(t,x(t))
            }
            //save the new state
            solution_.push_back(current_value_);
            //update time (incrementing time)
            t += dt_;
        }
    }

    // Getters for the results
    const std::vector<std::array<double, n>>& get_solution() const {
        return solution_;
    }

private: // private members of the class
    // Initial values for the ODE system
    std::array<double, n> initial_value_;

    // Current values for the ODE system
    std::array<double, n> current_value_;

    // Time variables
    double t0_, tf_, dt_;

    // The ODE system to be solved
    std::function<std::array<double, n>(double, std::array<double, n>)> ode_system_;

    // Solution vector
    std::vector<std::array<double, n>> solution_;
};

#endif // FORWARD_EULER_H
