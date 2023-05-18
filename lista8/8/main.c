#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

typedef
struct _TEMPO {
    int hora, minuto, segundo;
} TEMPO;

int comparaTempo(TEMPO t1, TEMPO t2)
{
    if (t1.hora > t2.hora)
        return 1;
    else if (t1.hora < t2.hora)
        return -1;
    else 
        if (t1.minuto > t2.minuto)
            return 1;
        else if (t1.minuto < t2.minuto)
            return -1;
        else 
            if (t1.segundo > t2.segundo)
                return 1;
            else if (t1.segundo < t2.segundo)
                return -1;
            else 
                return 0;
}

int leTarefa(TEMPO* t)
{
    printf("Escreva o tempo gasto na tarefa, em horas, minutos e segundos:\n");
    scanf("%i %i %i", &t->hora, &t->minuto, &t->segundo);

    if (t->minuto < 0 || t->minuto >= 60)
    {
        printf("Tempo inserido invalido. Abortando.\n");
        return 0;
    }

    if (t->segundo < 0 || t->segundo >= 60)
    {
        printf("Tempo inserido invalido. Abortando.\n");
        return 0;
    }

    return 1;
}

int main(void)
{
    TEMPO t1, t2, t3, t4, t5;
    TEMPO tAux;
    TEMPO tarefas[TAMANHO];

    if (!leTarefa(&t1)) exit(1);
    if (!leTarefa(&t2)) exit(1);
    if (!leTarefa(&t3)) exit(1);
    if (!leTarefa(&t4)) exit(1);
    if (!leTarefa(&t5)) exit(1);

    tarefas[0] = t1;
    tarefas[1] = t2;
    tarefas[2] = t3;
    tarefas[3] = t4;
    tarefas[4] = t5;

    for (int i = 0; i < TAMANHO - 1; i++) 
    {
        for (int j = 0; j < TAMANHO - i - 1; j++) 
        {
            if (comparaTempo(tarefas[j], tarefas[j+1]) > 0)
            {
                tAux = tarefas[j];
                tarefas[j] = tarefas[j + 1];
                tarefas[j + 1] = tAux;
            }
        }
    }

    puts("Tarefas ordenadas de forma crescente:\n");
    for (int i = 0; i < TAMANHO; i++) 
        printf("%ih %im %is\n", tarefas[i].hora, tarefas[i].minuto, tarefas[i].segundo);
    

    return 0;
}