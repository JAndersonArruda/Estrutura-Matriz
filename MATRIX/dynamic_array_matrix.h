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

int fetchPosition (Matrix * matrix, int row, int col) {
    int position = (row - 1) * matrix->cols + (col - 1);
    return position;
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
	int posicao = fetchPosition(matrix, row, col);
	matrix->data[posicao] = value;
}

void clearMatrix(Matrix * matrix){
	for (int row = 0; row < matrix->rows; row++){
        for (int col = 0; col < matrix->cols; col++){
            insertElementPosition(matrix, row + 1, col + 1, 0);
        }
	}
}

int fetchMatrix(Matrix * matrix, int row, int col) {
    int posicao = fetchPosition(matrix, row, col);
    int valor = matrix->data[posicao];
    return valor;
}

void printMatrix(Matrix * matrix) {
    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            printf("%2d ", fetchMatrix(matrix, row + 1, col + 1));
        }
        printf("\n");
    }
}

void freeMatrix(Matrix * matrix) {
    free(matrix->data);
}
