// Analisador lexico para identificadores

#include <stdio.h>
#include <stdlib.h>

char nextChar(FILE *file) {
    return fgetc(file);
}

int main() {
    // 1. Abrir arquivo de entrada e saída
    FILE *input_fptr, *output_fptr;

    input_fptr = fopen("sort.txt", "r");

    if (input_fptr == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    output_fptr = fopen("output.txt", "w");

    if (output_fptr == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(input_fptr);
        return 1;
    }

    // 2. Inicializar matrizes da tabela do algoritmo

    // Matriz de transição de estados
    int T[3][3];

    // Matriz avance
    int A[3][3];

    // Matriz de aceitação
    int F[3];

    // 3. Inicializar variáveis de controle

    char c;

    while (c = nextChar(input_fptr) != EOF) {
        // Identifica tokens de identificadores
        // Substitui os lexemas de identificadores por "ID" no arquivo de saída
    }
}