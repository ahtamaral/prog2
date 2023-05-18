#include <stdio.h>
#include <stdlib.h>

typedef struct _JOGADOR {
    int pontos;
    char nome[42];
} JOGADOR;

void leJogador(JOGADOR* j)
{
    puts("Insira o nome do jogador: ");
    scanf("%s", j->nome);
    puts("Insira a quantidade de pontos do jogador:");
    scanf("%d", &j->pontos);
}

int main(void)
{

    JOGADOR j;
    JOGADOR jogadores[5];

    for (int i = 0; i < 5; i++)
    {
        leJogador(&j);
        jogadores[i] = j;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s: %d pontos\n", jogadores[i].nome, jogadores[i].pontos);
    }
    
    return 0;
}