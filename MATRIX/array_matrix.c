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

void clearMatrix(int vet[TAMANHO]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            insertElement(vet, row + 1, col + 1, 0);
        }
    }
}

int fetchMatrix(int vet[TAMANHO], int row, int col) {
    int posicao = fetchPosition(row, col);
    int valor = vet[posicao];
    return valor;
}

void printMatrix(int vet[TAMANHO]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%2d ", vet[fetchPosition(row+1, col+1)]);
        }
        printf("\n");
    }
}

// Afunção somMatrix e  não salva em uma varialvel, apenas imprime a soma das duas
void sumMatrix(int vet1[TAMANHO], int vet2[TAMANHO]) {
    for (int row = 0; row < 3; row ++) {
        for (int col = 0; col < 3; col ++) {
            printf("%2d ", (vet1[fetchPosition(row +1, col +1)]) + (vet2[fetchPosition(row +1, col +1)]));
        }
        printf("\n");
    }
}

// Afunção subtractMatrix e  não salva em uma varialvel, apenas imprime a soma das duas
void subtractMatrix(int vet1[TAMANHO], int vet2[TAMANHO]) {
    for (int row = 0; row < 3; row ++) {
        for (int col = 0; col < 3; col ++) {
            printf("%2d ", (vet1[fetchPosition(row +1, col +1)]) - (vet2[fetchPosition(row +1, col +1)]));
        }
        printf("\n");
    }
}

/*
 - Multiplicação de matrizes

                             col0                                                  col1                                                  col2
row0  (r0,c0)*(r0,c0) + (r0,c1)*(r1,c0) + (r0,c2)*(r2,c0) | (r0,c0)*(r0,c1) + (r0,c1)*(r1,c1) + (r0,c2)*(r2,c1) | (r0,c0)*(r0,c2) + (r0,c1)*(r1,c2) + (r0,c2)*(r2,c2)
row1  (r1,c0)*(r0,c0) + (r1,c1)*(r1,c0) + (r1,c2)*(r2,c0) | (r1,c0)*(r0,c1) + (r1,c1)*(r1,c1) + (r1,c2)*(r2,c1) | (r1,c0)*(r0,c2) + (r1,c1)*(r1,c2) + (r1,c2)*(r2,c2)
row2  (r2,c0)*(r0,c0) + (r2,c1)*(r1,c0) + (r2,c2)*(r2,c0) | (r2,c0)*(r0,c1) + (r2,c1)*(r1,c1) + (r2,c2)*(r2,c1) | (r2,c0)*(r0,c2) + (r2,c1)*(r1,c2) + (r2,c2)*(r2,c2)

*/

void multiplyMatrix(int vet1[TAMANHO], int vet2[TAMANHO]) {
    for (int lop = 0; lop < 3; lop ++) {  //lop para pular de linha na impressão

        for (int col = 0; col < 3; col ++) {  // a coluna permanece a mesme durante a interação, assim ele mude apenas 3 veses
            int mult = 0;
            for (int row = 0; row < 3; row ++) {  // a linha irá mudar, a cada mudansa na linha multiplico
                mult += vet2[fetchPosition(row +1, col +1)] * vet1[fetchPosition(col +1, row +1)];
            }
            printf("%2d ", mult);
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