#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MAXIMO_CONTATOS 100
#define TAMANHO_MAXIMO_CAMPO 15

typedef struct _CONTATO 
{
    char nome[15];
    char telefone[15];
    char aniversario[5];
} CONTATO;

int carregarContatos(CONTATO contatos[], int* numContatos) {
    
    FILE* arq = fopen("contatos.txt", "r");
    
    if (arq == NULL) 
    {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }
    
    char linha [TAMANHO_MAXIMO_CAMPO * 3];

    printf("Contatos carregados:\n");

    while (fgets(linha, sizeof(linha), arq) != NULL) 
    {
        char* token;
        token = strtok(linha, ",");
        
        strcpy(contatos[*numContatos].nome, token);
        token = strtok(NULL, ",");
        strcpy(contatos[*numContatos].telefone, token);
        token = strtok(NULL, ",");
        strcpy(contatos[*numContatos].aniversario, token);

        (*numContatos)++;
    }
    puts("");

    fclose(arq);
    return 0;
}

void exibirContatos(CONTATO contatos[], int numContatos)
{
    printf("Contact List:\n");
    for (int i = 0; i < numContatos; i++) 
    {
        printf("%s %s %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversario);
    }
}

int insereContato(CONTATO contato)
{
    char linha[40];
    FILE *arq;
    short ret;

    strcpy(linha, contato.nome);
    strcat(linha, ",");
    strcat(linha, contato.telefone);
    strcat(linha, ",");
    strcat(linha, contato.aniversario);
    strcat(linha, "\n");

    arq = fopen("contatos.txt", "a");
    if (arq == NULL)
        return 1;
    ret = fprintf(arq, "%s", linha);    

    return 0;
}

int removeContato()
{
    return 0;
}

int pesquisaPorNome()
{
    return 0;
}

int listarContatos()
{
    return 0;
}

int listarContatosPorLetraInicial()
{
    return 0;
}

int listaAniversariantes()
{
    return 0;
}

int main()
{
    char op;
    short execute= 1;
    int ret;
    int numContatos = 0;
    CONTATO contato;
    CONTATO contatos[NUM_MAXIMO_CONTATOS];
    FILE *arq;

    carregarContatos(contatos, &numContatos);
    
    for (int i = 0; i < numContatos; i++) 
    {
        printf("%s %s %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversario);
    }
    

    arq = fopen("contatos.txt", "r");
    if (arq == NULL)
    {
        puts("Arquivo de contatos nao pode ser aberto.");
        puts("Crie um arquivo chamado \"contatos.txt\" no diretorio do executavel e tente novamente.\nAbortando programa.");
        exit(1);
    }

    if (contatos == NULL)
    {
        puts("Erro ao tentar carregar arquivo em memoria. Abortando.");
        exit(1);
    }
    

    puts("=== AGENDA ===");
    puts("");
    puts("(a) inserir contato");
    puts("(b) remover contato");
    puts("(c) pesquisar um contato pelo nome");
    puts("(d) listar todos os contatos");
    puts("(e) listar os contatos cujo nome inicia com uma dada letra");
    puts("(f) imprimir os aniversariantes do mês");
    puts("");

    puts("Insira uma das letras: ");
    op = getchar();

    switch (op)
    {
    case 'a':
        puts("Nome:");
        scanf("%s", contato.nome);
        puts("Telefone:");
        scanf("%s", contato.telefone);
        puts("Aniversario (DD/MM):");
        scanf("%s", contato.aniversario);

        ret = insereContato(contato);

        if (ret != 0)
        {
            puts("Nao foi possivel inserir o contato. Voltando ao menu.");
        } 
        else
        {
            puts("Contato inserido com sucesso.");
        }
        break;

    case 'b':
        /* code */
        break;
    case 'c':
        puts("C");
        break;
    case 'd':
        /* code */
        break;
    case 'e':
        /* code */
        break;
    case 'f':
        puts("F");
        break;
    
    default:
        puts("Entrada invalida.");
        break;
    }

    fclose(arq);

    return 0;
}