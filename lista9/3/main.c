#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para armazenar os dados do vendedor
typedef struct {
    int codigo_vendedor;
    char nome_vendedor[50];
    float valor_venda;
    int mes_da_venda;
} VENDEDOR;

// Função para criar o arquivo de dados
void criarArquivo() {
    FILE *arquivo = fopen("vendedores.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }
    fclose(arquivo);
    printf("Arquivo criado com sucesso.\n");
}

// Função para incluir um registro no arquivo
void incluirRegistro() {
    VENDEDOR vendedor;
    printf("Digite o código do vendedor: ");
    scanf("%d", &vendedor.codigo_vendedor);

    // Verifica se o registro já existe no arquivo
    FILE *arquivo = fopen("vendedores.dat", "rb");
    if (arquivo != NULL) {
        VENDEDOR temp;
        while (fread(&temp, sizeof(VENDEDOR), 1, arquivo)) {
            if (temp.codigo_vendedor == vendedor.codigo_vendedor) {
                printf("Já existe um registro com esse código de vendedor.\n");
                fclose(arquivo);
                return;
            }
        }
        fclose(arquivo);
    }

    printf("Digite o nome do vendedor: ");
    scanf(" %[^\n]s", vendedor.nome_vendedor);
    printf("Digite o valor da venda: ");
    scanf("%f", &vendedor.valor_venda);
    printf("Digite o mês da venda: ");
    scanf("%d", &vendedor.mes_da_venda);

    // Abre o arquivo no modo de escrita binária (append)
    arquivo = fopen("vendedores.dat", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(&vendedor, sizeof(VENDEDOR), 1, arquivo);
    fclose(arquivo);
    printf("Registro incluído com sucesso.\n");
}

// Função para excluir um registro do arquivo
void excluirRegistro() {

}

// Função para alterar o valor de uma venda no arquivo
void alterarValorVenda() {
    int codigo;
    printf("Digite o código do vendedor: ");
    scanf("%d", &codigo);

    FILE *arquivo = fopen("vendedores.dat", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    VENDEDOR vendedor;
    int encontrado = 0;
    while (fread(&vendedor, sizeof(VENDEDOR), 1, arquivo)) {
        if (vendedor.codigo_vendedor == codigo) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        float novo_valor;
        printf("Digite o novo valor da venda: ");
        scanf("%f", &novo_valor);
        vendedor.valor_venda = novo_valor;
        fseek(arquivo, -sizeof(VENDEDOR), SEEK_CUR);
        fwrite(&vendedor, sizeof(VENDEDOR), 1, arquivo);
        printf("Valor da venda alterado com sucesso.\n");
    } else {
        printf("Registro não encontrado.\n");
    }

    fclose(arquivo);
}

// Função para imprimir os registros na saída padrão
void imprimirRegistros() {
    FILE *arquivo = fopen("vendedores.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    VENDEDOR vendedor;
    printf("Código\tNome\t\tValor Venda\tMês\n");
    printf("------\t----\t\t-----------\t---\n");
    while (fread(&vendedor, sizeof(VENDEDOR), 1, arquivo)) {
        printf("%d\t%s\t%.2f\t\t%d\n", vendedor.codigo_vendedor, vendedor.nome_vendedor,
               vendedor.valor_venda, vendedor.mes_da_venda);
    }

    fclose(arquivo);
}

// Função para excluir o arquivo de dados
void excluirArquivo() {
    int resultado = remove("vendedores.dat");
    if (resultado == 0) {
        printf("Arquivo excluído com sucesso.\n");
    } else {
        printf("Erro ao excluir o arquivo.\n");
    }
}

int main() {
    int opcao;

    while (1) {
        printf("\nMenu:\n");
        printf("1 - Criar o arquivo de dados\n");
        printf("2 - Incluir um registro no arquivo\n");
        printf("3 - Excluir um vendedor no arquivo\n");
        printf("4 - Alterar o valor de uma venda no arquivo\n");
        printf("5 - Imprimir os registros\n");
        printf("6 - Excluir o arquivo de dados\n");
        printf("7 - Finalizar o programa\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarArquivo();
                break;
            case 2:
                incluirRegistro();
                break;
            case 3:
                // excluirRegistro();
                break;
            case 4:
                alterarValorVenda();
                break;
            case 5:
                imprimirRegistros();
                break;
            case 6:
                excluirArquivo();
                break;
            case 7:
                printf("Programa finalizado.\n");
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}