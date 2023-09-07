#include <stdio.h>
#include <stdlib.h>

struct Matrix;
struct createMatrix;

Matrix multiplyMatrix(Matrix * matrix1, Matrix * matrix2) {
    if (matrix1->cols == matrix2->rows){
        Matrix resultado = createMatrix(matrix1->rows, matrix2->cols);
        for (int row = 0; row < matrix1->rows; row++) {
            for (int col = 0; col < matrix2->cols; col++) {
                //resultado->data[row * resultado->cols + col] percorro as posições da matriz resultado;
                int posicaoResultado = row * matrix2->cols + col;
                for (int col1 = 0; col1 < matrix1->cols; col1++) {
                    int posMat1 = row * matrix1->cols + col1;
                    int posMat2 = col1 * matrix2->cols + col;
                    resultado.data[posicaoResultado] += matrix1->data[posMat1] * matrix2->data[posMat2];
                }
            }
        }

        return resultado;
    }
}