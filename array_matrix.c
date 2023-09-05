// Desenvolvendo matriz a partir de um vetor estático;

/*
- Create Matrix (rows, columns)
- Inserir Value (matrix, row, column, value)
- Update Value (matrix, row, column, value)
- Delete Value (matrix, row, column)
- Serch Value (matrix, row, column)

*QUANDO SOMAR UM PONTEIRO COM UM INT, ELE CONSIDERA BYTE (4 BYTES). Ex. 1431671456 + 1 = 1431671460
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

const int TAMANHO = 9;

int fetchPosition (int row, int col) {
    int position = (row - 1) * 3 + (col - 1);
    return position;
}

void clearMatrix(int vet[TAMANHO]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            insertElement(vet, row + 1, col + 1, 0);
        }
    }
}

void insertElement(int vet[TAMANHO], int row, int col, int value) {
    int posicao = fetchPosition(row, col);
    vet[posicao] = value;
}

void insertRandomElement (int vet[TAMANHO], int limite) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int posicao = fetchPosition(row + 1, col + 1);
            vet[posicao] = rand() % limite;
        }
    }

	// for (int k = 0; k < TAMANHO; k++){
	// 	//Gerando valores de 0 a 100
	// 	vet[k] = rand() % limite;
	// }
}

int fetchMatrix(int vet[TAMANHO], int row, int col) {
    int posicao = (row - 1) * 3 + (col - 1);
    int valor = vet[posicao];
    return valor;
}

void printMatrix(int vet[TAMANHO]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", vet[i * 3 + j]);
        }
        printf("\n");
    }
}

void main() {
    srand(time(NULL));

    int vet[TAMANHO];
    clearMatrix(vet);

    printMatrix(vet);
    printf("\n");
    
    insertRandomElement(vet, 9);
    printMatrix(vet);
    printf("\n");

    insertElement(vet, 1, 1, 2);
    printMatrix(vet);
    printf("\n");
    
    printf("%2d\n", fetchMatrix(vet, 1, 1));
    printf("\n");

    printMatrix(vet);
    printf("\n");
}