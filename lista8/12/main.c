#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

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
    JOGADOR jogadores[6];
    JOGADOR jAux;

    for (int i = 0; i < 5; i++)
    {
        leJogador(&j);
        jogadores[i] = j;
    }

    for (int i = 0; i < TAMANHO - 1; i++) 
    {
        for (int j = 0; j < TAMANHO - i - 1; j++) 
        {
            if (jogadores[j].pontos > jogadores[j+1].pontos)
            {
                jAux = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = jAux;
            }
        }
    }


    for (int i = 4; i >= 0; i--)
    {
        printf("%s: %d pontos\n", jogadores[i].nome, jogadores[i].pontos);
    }

    leJogador(&j);
    jogadores[5] = j;

    for (int i = 0; i < TAMANHO+1 - 1; i++) 
    {
        for (int j = 0; j < TAMANHO+1 - i - 1; j++) 
        {
            if (jogadores[j].pontos > jogadores[j+1].pontos)
            {
                jAux = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = jAux;
            }
        }
    }

    for (int i = 5; i >= 1; i--)
    {
        printf("%s: %d pontos\n", jogadores[i].nome, jogadores[i].pontos);
    }

    return 0;
}