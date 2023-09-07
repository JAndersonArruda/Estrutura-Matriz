#include <stdio.h>
#include <stdlib.h>

FILE *openFIle(char nome[25], char mode[5]) {
    FILE *file;
    file = fopen(nome, mode);

    return file;
}
