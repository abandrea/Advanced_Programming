#ifndef FORWARDEULER_H
#define FORWARDEULER_H

#include <array>
#include <vector>
#include <functional>

template<size_t n>
class ForwardEuler{
    // ForwardEuler è una classe template che risolve un sistema di equazioni differenziali ordinarie (ODE) di n variabili
public:
// questa classe ha un costruttore e tre metodi pubblici
//servono per inizializzare l'oggetto, risolvere l'ODE e ottenere la soluzione
    ForwardEuler(std::function<std::array<double, n>(double, const std::array<double, n>&)> f) : func(f) {}

    void setInitialValue(const std::array<double, n>& y0) {
        this->y0 = y0;
    }

    void solve(double t0, double tf, double dt);

    const std::vector<std::array<double, n>>& getSolution() const {
        return solution;
    }

private:
// questa classe ha tre membri privati: una funzione, un vettore e un array
    std::function<std::array<double, n>(double, const std::array<double, n>&)> func;
    std::vector<std::array<double, n>> solution;
    std::array<double, n> y0;
};

template<size_t n>
void ForwardEuler<n>::solve(double t0, double tf, double dt) { // Metodo per risolvere l'ODE
    // Definizioni delle funzioni di sovraccarico
    auto add_arrays = [](const std::array<double, n>& a, const std::array<double, n>& b) {
        std::array<double, n> result;
        for (size_t i = 0; i < n; ++i) {
            result[i] = a[i] + b[i];
        }
        return result;
    }; 
// sviluppato in modo che possa essere utilizzato con qualsiasi numero di variabili


    auto scalar_multiply_array = [](double scalar, const std::array<double, n>& array) {
        std::array<double, n> result;
        for (size_t i = 0; i < n; ++i) {
            result[i] = scalar * array[i];
        }
        return result;
    };

    std::array<double, n> y = y0;
    double t = t0;

    while (t <= tf) {
        solution.push_back(y);
        y = add_arrays(y, scalar_multiply_array(dt, func(t, y)));
        t += dt;
    }
}

#endif

