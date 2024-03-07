

#include "ForwardEuler.h"
#include <iostream>
#include <cmath>
#include <fstream> // Per la scrittura su file dei risultati


int main() {
    //oggetto per scrivere su file
    std::ofstream file("results.txt");

    // Decadimento esponenziale
    const double k = 0.1; // Decay constant
    auto decayFunc = [k](double t, const std::array<double, 1>& y) { // Function to solve
        return std::array<double, 1>{-k * y[0]};
    };

    ForwardEuler<1> decaysolver(decayFunc); // Create an instance of ForwardEuler
    decaysolver.setInitialValue({5.0}); // Set the initial value of y
    decaysolver.solve(0, 10, 0.1); // Solve the ODE

    const auto& decaysolution = decaysolver.getSolution(); // Get the solution
    for (const auto& point : decaysolution) { // Print the results
        //std::cout << "y = " << point[0] << std::endl; // stampa i risultati a schermo terminale
        file << "Decadimento esponenziale, y= " << point[0] << std::endl; // scrive i risultati su file
    }

    file << "\n \n"; // separa i risultati dei due esempi
///-------------------------------------------------------------------------------------------------------------------------
    // Parametri Lotka-Volterra
    double alpha = 0.1;
    double beta = 0.02;
    double gamma = 0.3;
    double delta = 0.01;

    // Sistema Lotka-Volterra
    auto lotkaVolterra = [alpha, beta, gamma, delta](double t, const std::array<double, 2>& values) {
        double x = values[0]; // Prede
        double y = values[1]; // Predatori
        return std::array<double, 2>{alpha * x - beta * x * y, delta * x * y - gamma * y};
    };

    // Inizializzazione del solver
    ForwardEuler<2> lovolsolver(lotkaVolterra); // lovolsolver è un'istanza di ForwardEuler per separare le due soluzioni
    lovolsolver.setInitialValue({40.0, 9.0}); // Valore iniziale per prede (x) e predatori (y)

    // Risoluzione del sistema
    lovolsolver.solve(0, 200, 0.05); // t0, tf, dt

    // Stampa dei risultati
    const auto& lovolsolution = lovolsolver.getSolution();
    for (const auto& point : lovolsolution) {
        //std::cout << "Prede: " << point[0] << ", Predatori: " << point[1] << std::endl; // stampa i risultati a schermo terminale
        file << "Lotka-Volterra, Prede: " << point[0] << ", Predatori: " << point[1] << std::endl; // scrive i risultati su file
    }
///-------------------------------------------------------------------------------------------------------------------------
    // Scrittura dei risultati su file
    file.close(); // Chiude il file
    std::cout << "Risultati scritti su file results.txt" << std::endl; // stampa a schermo terminale
    std::cout << "!!! ATTENZIONE !!! : \n!!!!!!!!!!\nSALVARE I RISULTATI PRIMA DI RILANCIARE IL PROGRAMMA" << std::endl; // stampa a schermo terminale
    std::cout << "Per visualizzare i risultati, aprire il file results.txt" << std::endl; // stampa a schermo terminale

    return 0; // Return 0 to indicate success \m/_  _\m/ 
}


//g++ -o FE_test main.cpp -std=c++17
//./FE_test
//y = 5
//y = 4.5
//y = 4.05
//...
//y = 1.83016