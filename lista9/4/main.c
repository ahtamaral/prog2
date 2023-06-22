#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char inputFileName[100];
    char pattern[100];

    // Solicitar o nome do arquivo de entrada e o padrão ao usuário
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", inputFileName);
    printf("Digite o padrão a ser encontrado: ");
    scanf("%s", pattern);

    // Abrir o arquivo de entrada para leitura
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int patternFound = 0;

    // Percorrer as linhas do arquivo de entrada
    while (fgets(line, sizeof(line), inputFile)) {
        lineNumber++;

        // Verificar se o padrão ocorre na linha
        if (strstr(line, pattern) != NULL) {
            patternFound = 1;

            // Exibir o número da linha e a linha encontrada
            printf("Padrão encontrado na linha %d: %s", lineNumber, line);
        }
    }

    // Verificar se o padrão não foi encontrado
    if (!patternFound) {
        printf("Padrão não encontrado no arquivo.\n");
    }

    // Fechar o arquivo de entrada
    fclose(inputFile);

    return 0;
}