#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array_matrix.h"
#include "math_matrix.h"

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