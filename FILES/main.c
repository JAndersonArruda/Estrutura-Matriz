#include <stdio.h>
#include <stdlib.h>

FILE *openFIle(char nome[25], char mode[5]) {
    FILE *file;
    file = fopen(nome, mode);

    return file;
}

void closeFile(FILE *file) {
    fclose(file);
}

void readFile(char nome[25]) {
    FILE *file = openFIle(nome, "r");

    char frase[50];
    while (fgets(frase, 10, file) != NULL)
    {
        printf("%s", frase);
    }

    closeFile(file);
}

void whiteFile(char nome[25], char texto[100]) {
    FILE *file = openFIle(nome, "w");

    fprintf(file, texto);

    closeFile(file);
}
