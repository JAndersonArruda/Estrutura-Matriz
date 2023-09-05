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
