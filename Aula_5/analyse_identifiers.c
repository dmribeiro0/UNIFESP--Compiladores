// Analisador lexico para identificadores

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

// Simbolos de transicao e seus respectivos indices nas matrizes
#define letra 0
#define digito 1
#define outro 2

int nextChar(FILE *file) {
    return fgetc(file);
}

bool isPalavraReservada(char *string) {
    // Lista de palavras reservadas da linguagem C
    const char *palavrasReservadas[] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };
    int quantidade = sizeof(palavrasReservadas) / sizeof(palavrasReservadas[0]);

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(string, palavrasReservadas[i]) == 0) {
            return true;
        }
    }

    return false;
}

bool isLetra(char c) {
    if (c >= 65 && c <= 90 || c >= 97 && c <= 122) return true;
    return false;
}

bool isDigito(char c) {
    if (c >= 48 && c <= 57) return true;
    return false;
}

int getCharSymbol(char c) {
    if (isLetra(c)) {
        return letra;
    }
    else if (isDigito(c)) {
        return digito;
    }
    else {
        return outro;
    }
}

void copyToOutput(FILE *file, char *string) {
    fputs(string, file);
}

void writeIDtoOutput(FILE *file) {
    fputs("ID", file);
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
        {true, true, true},
        {true, true, false},
        {true, true, true}
    };

    // Matriz de aceitação
    bool F[3] = {false, false, true};

    // 3. Inicializar variáveis de controle

    int c;
    int currentState = 0, nextState;
    bool consumeNext;
    int charSymbol;
    char buffer[MAX_BUFFER_SIZE];
    int idx = 0;

    c = nextChar(input_fptr); // Primeiro caractere do arquivo

    // Identifica tokens de identificadores
    // Substitui os lexemas de identificadores por "ID" no arquivo de saída
    while (c != EOF) {
        // Passo 1. Processar caractere e calcular proximo estado
        charSymbol = getCharSymbol(c);              // Define o simbolo de transicao (letra, digito ou outro)
        nextState = T[currentState][charSymbol];    // Calcula proximo estado a partir de 'currentState' e consumindo 'charSymbol'
        consumeNext = A[currentState][charSymbol];  // Diz se o algoritmo deve ou nao consumir o proximo caractere
        
        // Passo 2. Consumir proximo caractere (e adiciona-lo ao buffer) ou nao
        if (consumeNext) {
            buffer[idx++] = c;
            c = nextChar(input_fptr);

        }
        // Passo 3. Processar proximo estado
        if (nextState == -1) {
            // Nao ha transicao (string nao pertence a linguagem), nesse caso:
            // 1. Escreva o conteudo sem alteracao no arq de saida 
            // 2. Volte para o estado inicial
            buffer[idx] = '\0';
            copyToOutput(output_fptr, buffer);
            nextState = 0;
            idx = 0;
        }
        else if (F[nextState]) {
            // Estado Final: String pertence a linguagem, nesse caso:
            // 1. Escreva ID no lugar dela no arq de saida
            // 2. Retorne para o estado inicial
            // Tratamento de palavras reservadas
            buffer[idx] = '\0';
            if (isPalavraReservada(buffer)) {
                copyToOutput(output_fptr, buffer);
            } else {
                writeIDtoOutput(output_fptr);
            }
            nextState = 0;
            idx = 0;
        }

        currentState = nextState;
    }

    // Se o arquivo terminar no meio de um identificador (estado 1),
    // trate isso como aceitacao, ja que o EOF funciona como delimitador implicito
    if (currentState == 1) {
        writeIDtoOutput(output_fptr);
    }

    fclose(input_fptr);
    fclose(output_fptr);

    return 0;
}