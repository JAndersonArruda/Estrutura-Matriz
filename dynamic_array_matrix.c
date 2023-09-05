#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int rows;
    int cols;
    int *data;
    int *lastElement;
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int *)malloc(rows * cols * sizeof(int));
    matrix.lastElement = matrix.data;
    return matrix;
}

void clearMatrix(Matrix * matrix){
	for (int k = 0; k < matrix->rows * matrix->cols; k++){
		matrix->data[k] = 0;
	}
}


void insertElement(Matrix * matrix, int value) {
    if (matrix->lastElement < matrix->data + matrix->rows * matrix->cols) {
        *(matrix->lastElement) = value;
        matrix->lastElement++;
    }
}

void insertRandomElement(Matrix * matrix, int limite) {
	for (int k = 0; k < matrix->rows * matrix->cols; k++){
		//Gerando valores de 0 a 100
		matrix->data[k] = rand() % limite;
	}
}

void insertElementPosition(Matrix * matrix, int row, int col, int value){
	int posicao = (row - 1) * matrix->cols + (col - 1);
	matrix->data[posicao] = value;
}

int fetchMatrix(Matrix * matrix, int row, int col) {
    int posicao = (row - 1) * matrix->cols + (col - 1);
    int valor = matrix->data[posicao];
    return valor;
}

void printMatrix(Matrix * matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%2d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void freeMatrix(Matrix * matrix) {
    free(matrix->data);
}
/*
 1  2  3
 4  5  6

 1  2
 3  4
 5  6

[1, 2, 3, 4, 5, 6] x [1, 2, 3, 4, 5, 6]

*/


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

void main() {
    Matrix mat = createMatrix(2, 3);
    Matrix mat1 = createMatrix(3, 2);

    insertRandomElement(&mat, 10);
    insertRandomElement(&mat1, 10);
    printMatrix(&mat);
    printMatrix(&mat1);

    multiplyMatrix(&mat, &mat1);

    Matrix resultado = multiplyMatrix(&mat, &mat1);
    printMatrix(&resultado);

    freeMatrix(&mat);
    freeMatrix(&mat1);
}