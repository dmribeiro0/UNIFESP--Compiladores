// Analisador lexico para identificadores

#include <stdio.h>
#include <stdlib.h>

// Simbolos de transicao e seus respectivos indices nas matrizes
#define letra 0
#define digito 1
#define outro 2

char nextChar(FILE *file) {
    return fgetc(file);
}

bool letra(char c) {
    if (c >= 65 && c <= 90 || c >= 97 && c <= 122) return true;
}

bool digito(char c) {
    if (c >= 48 && c <= 57) return true;
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

    // 2. Inicializar matrizes do AFD
    // Estados: (0, 1, 2)
    // Transicoes: letra (0) | digito (1) | outro (2)

    // Matriz de transição de estados
    int T[3][3] = {
        {1, -1, -1},
        {1, 1, 2},
        {-1, -1, -1}
    };

    // Matriz avance
    bool A[3][3] = {
        {true, false, false},
        {true, true, false},
        {false, false, false}
    };

    // Matriz de aceitação
    bool F[3] = {false, false, true};

    // 3. Inicializar variáveis de controle

    char c;

    while (c = nextChar(input_fptr) != EOF) {
        // Identifica tokens de identificadores
        // Substitui os lexemas de identificadores por "ID" no arquivo de saída
    }
}