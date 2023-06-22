#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 50
#define MAX_LINES 1000

void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char inputFileName[100];
    char outputFileName[100];

    // Solicitar o nome dos arquivos de entrada e saída ao usuário
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", inputFileName);
    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", outputFileName);

    // Abrir o arquivo de entrada para leitura
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abrir o arquivo de saída para escrita
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(inputFile);
        return 1;
    }

    char lines[MAX_LINES][MAX_CHARACTERS + 1];
    int lineNumber = 0;

    // Ler as linhas do arquivo de entrada
    while (fgets(lines[lineNumber], sizeof(lines[lineNumber]), inputFile)) {
        lineNumber++;

        // Verificar se o número de linhas excede o limite
        if (lineNumber >= MAX_LINES) {
            printf("Erro: O número de linhas excede o limite permitido.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }
    }

    // Escrever as linhas invertidas no arquivo de saída
    for (int i = lineNumber - 1; i >= 0; i--) {
        reverseString(lines[i]);
        fprintf(outputFile, "%s", lines[i]);
    }

    // Fechar os arquivos
    fclose(inputFile);
    fclose(outputFile);

    printf("Processo concluído. O arquivo de saída foi gerado com sucesso.\n");

    return 0;
}