  # Sostituisci con il percorso effettivo

# Importa la libreria
from matrixlib import Matrix

# crea e testa un oggetto di tipo Matrix
mat = Matrix(3, 3)
mat.set(1, 1, 5.0)
mat.set(1, 2, 6.0)
mat.set(1, 3, 6.0)
mat.set(2, 1, 8.0)
mat.set(2, 2, 9.0)
mat.set(2, 3, 10.0)
mat.set(3, 1, 11.0)
mat.set(3, 2, 12.0)
mat.set(3, 3, 13.0)

print("Printing the matrix:\n") 
mat.print()

print("Value at (1, 1):", mat.get(1, 1), "\n")

if mat.Determinant() !=0: 
    print("Matrix determinant:", mat.Determinant())
else:
    print("Matrix is singular")

try:
    inverse_matrix = mat.Inverse()
    print("Matrix inverse:\n", inverse_matrix)
except IndexError as e:
    print("Errore durante il calcolo dell'inversa: ", e)




# if mat.Determinant() != 0:
#     print("Matrix inverse:\n", mat.Inverse())
# else:
#     print("Matrix is not invertible")




# print("Matrix transpose:", mat.transpose())
# print("Matrix addition:", mat.add(mat))
# print("Matrix subtraction:", mat.subtract(mat))
# print("Matrix multiplication:", mat.multiply(mat))
