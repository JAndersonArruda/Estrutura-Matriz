# Arquivos em C

## Operações com arquivos

1. Criar um arquivo
2. Abrir um arquivo existente
3. Fechar um arquivo
4. Lendo e gravando informações em um arquivo

## Abrindo um arquivo

Criamos um ponteiro do tipo FILE para declarar um arquivo:

```C
FILE *file;
```

Agora, para abrir e utilizar o arquivo usamos a `fopen()` função definida no `stdio.h`.
```C
file = fopen("filePath","mode");
```

| Modo | Significado do modo | if inexistência |
|------|---------------------|----------------|
| `r` | Aberto para leitura. | Se o arquivo não existir, `fopen()` retorna NULL. |
| `rb` | Aberto para leitura em modo binário. |	Se o arquivo não existir, `fopen()` retorna NULL. |
| `w` | Aberto para escrita. | Se o arquivo existir, seu conteúdo será sobrescrito. Se o arquivo não existir, ele será criado. |
| `wb` | Aberto para escrita em modo binário. | Se o arquivo existir, seu conteúdo será sobrescrito. Se o arquivo não existir, ele será criado.
| `a` | Aberto para anexar. | Os dados são adicionados ao final do arquivo. Se o arquivo não existir, ele será criado. |
| `ab` | Aberto para acréscimo no modo binário. | Os dados são adicionados ao final do arquivo. Se o arquivo não existir, ele será criado. |
| `r+` | Aberto para leitura e escrita. | Se o arquivo não existir, `fopen()` retorna NULL. |
| `rb+` | Aberto para leitura e escrita em modo binário. | Se o arquivo não existir, `fopen()` retorna NULL. |
| `w+` | Aberto para leitura e escrita. | Se o arquivo existir, seu conteúdo será sobrescrito. Se o arquivo não existir, ele será criado. |
| `wb+` | Aberto para leitura e escrita em modo binário. | Se o arquivo existir, seu conteúdo será sobrescrito. Se o arquivo não existir, ele será criado. |
| `a+` | Aberto para leitura e acréscimo. | Se o arquivo não existir, ele será criado. |
| `ab+` |	Aberto para leitura e acréscimo no modo binário. | Se o arquivo não existir, ele será criado. |

## Fechando um arquivo

O arquivo (texto e binário) deve ser fechado após leitura/gravação.

```C
fclose(file);
```

## CRUD em arquivo

>### Escrevendo
Utilizamos `fprintf(file, char *str,...);` para imprimir no arquivo.

| Função | Descrição |
|--------|-----------|
| `fprintf()` | Semelhante a `printf()`, esta função usa uma string formatada e uma lista de argumentos variáveis ​​para imprimir a saída no arquivo. |
| `entradas()` | Imprime a linha inteira do arquivo e uma nova linha no final. |
| `fputc()` | Imprime um único caractere no arquivo. |
| `fputw()`	| Imprime um número no arquivo. |
| `escrever()` | Esta função grava a quantidade especificada de bytes no arquivo binário. |

Outras funções: `fputs();`.

>### Lendo
Utilizamos `fscanf (file, char *str,...);`, mas temos que saber qual o tipo de saida.
```C
char frase[50];
while (fscanf(file, "%s", &frase) != EOF)
{
    printf("%s ", frase);
}
```

| Função | Descrição |
|--------|-----------|
| `fscanf()` | Use uma string formatada e uma lista de argumentos variáveis ​​para obter a entrada de um arquivo. |
| `get()`	| Insira a linha inteira do arquivo. |
| `fgetc()` | Lê um único caractere do arquivo. |
| `getw()` | Lê um número de um arquivo. |
| `pão()` | Lê os bytes de dados especificados de um arquivo binário. |

```c
char frase[50];
while (fgets(frase, 10, file) != NULL)
{
    printf("%s", frase);
}
```

### Buscando
`fseek()`, `rewind()`

Outras funções: `fgets();`, `fgetchar();` ou `fputc();`.
>### Atualizando

>### Deletando