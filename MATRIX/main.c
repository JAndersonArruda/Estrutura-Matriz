#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array_matrix.h"
#include "math_matrix.h"

void main() {
    Matrix mat = createMatrix(3, 3);
    clearMatrix(&mat);
    printMatrix(&mat);
    printf("\n");

    insertElement(&mat, 1);
    printMatrix(&mat);
    printf("\n");

    insertElementPosition(&mat, 2, 3, 2);
    printMatrix(&mat);
    printf("\n");

    insertRandomElement(&mat, 10);
    printMatrix(&mat);
    printf("\n");

    freeMatrix(&mat);
}