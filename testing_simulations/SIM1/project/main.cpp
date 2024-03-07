#include "Matrix.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"

#include <iostream>
#include <iomanip>


int main() {
    //matrice 3x3 per test
    Matrix matrice(3, 3);

    // aggiungere codice per manipolare o testare la tua matrice
    // La compilazione di matrice.set:
    // primi due valori sono le coordinate della matrice
    // l'ultimo valore è il valore da inserire nella matrice
    

    //test matrice 3x3
    // impostare i valori della matrice
    matrice.set(1, 1, 1.0); // Imposta l'elemento in posizione (1,1) a 1.0
    matrice.set(1, 2, 2.0); // imposta l'elemento in posizione (1,2) a 2.0
    matrice.set(1, 3, 2.0); // impostare l'elemento in posizione (1,3) a 3.0
    matrice.set(2, 1, 4.0); // ecc..
    matrice.set(2, 2, 5.0); // 
    matrice.set(2, 3, 6.0); // 
    matrice.set(3, 1, 7.0); // 
    matrice.set(3, 2, 8.0); // 
    matrice.set(3, 3, 9.0); // 

    // stampare la matrice
    matrice.print();

    // ottenere il valore di un elemento
    std::cout << "Elemento (1,1): " << matrice.get(1, 1) << std::endl;
    std::cout << "Elemento (2,2): " << matrice.get(2, 2) << std::endl;
    // ottenere il numero di righe e colonne
    std::cout << "Numero di righe: " << matrice.getRows() << std::endl;
    std::cout << "Numero di colonne: " << matrice.getCols() << std::endl;

    //  test determinante 
    std::cout << "Determinante: " << matrice.determinant() << std::endl;

    //  test trasposta
    Matrix trasposta = matrice.transpose();
    std::cout << "Trasposta: " << std::endl;
    trasposta.print();

    //  test inversa
    Matrix inversa = matrice.inverse();
    std::cout << "Inversa: " << std::endl;
    inversa.print();
    

    return 0;

}



