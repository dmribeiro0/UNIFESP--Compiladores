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

int getCharSymbol(char c) {
    if (letra(c)) {
        return letra;
    }
    else if (digito(c)) {
        return digito;
    }
    else {
        return outro;
    }
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
    // -1 representa ausencia de transicao
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
    int currentState = 0, nextState;
    int charSymbol;
    FILE *start, *end;

    c = nextChar(input_fptr); // Primeiro caractere do arquivo

    // Identifica tokens de identificadores
    // Substitui os lexemas de identificadores por "ID" no arquivo de saída
    while (c != EOF) {
        // Passo 1. Consumir caractere e calcular proximo estado 
        charSymbol = getCharSymbol(c) // Define o simbolo de transicao (letra, digito ou outro)
        nextState = T[currentState][charSymbol]; // Calcula proximo estado a partir de 'currentState' e consumindo 'charSymbol'
        switch(nextState) {
            case -1:
                // Estado -1: Nao ha transicao em 'state' ao consumir 'charSymbol'
                // String nao eh um identificador, voltar para Estado 0
                nextState = 0;
                break;
            case 0:
                // Estado 0: Primeiro caractere de possivel ID
                // Salvar ponteiro para esse caractere
                start = input_fptr;
                break;
            case 1:
                // Estado 1: Analisando possivel ID
                break;
            case 2:
                // Estado 2: ID encontrado
                // Nesse momento input_fptr aponta para 
                break;
        }
    }
}