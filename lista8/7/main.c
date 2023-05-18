#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    TEMPO t1, t2;
    unsigned short rc;


    printf("Escreva o tempo gasto na primeira tarefa, em horas, minutos e segundos:\n");
    scanf("%i %i %i", &t1.hora, &t1.minuto, &t1.segundo);

    if (t1.minuto < 0 || t1.minuto >= 60)
    {
        printf("Tempo inserido invalido. Abortando.\n");
        exit(1);
    }

    if (t1.segundo < 0 || t1.segundo >= 60)
    {
        printf("Tempo inserido invalido. Abortando.\n");
        exit(1);
    }

    printf("Escreva o tempo gasto na segunda tarefa, em horas, minutos e segundos:\n");
    scanf("%i %i %i", &t2.hora, &t2.minuto, &t2.segundo);

    if (t2.minuto < 0 || t2.minuto >= 60)
    {
        printf("Tempo inserido invalido. Abortando.\n");
        exit(1);
    }

    if (t2.segundo < 0 || t2.segundo >= 60)
    {
        printf("Tempo inserido invalido. Abortando.\n");
        exit(1);
    }

    rc = comparaTempo(t1, t2);

    if (rc > 0)
    {
        printf("\nA primeira tarefa foi mais longa, durando %ih %im %is\n\n", t1.hora, t1.minuto, t1.segundo);
    }
    else if (rc < -1)
    {
        printf("\nA segunda tarefa foi mais longa, durando %ih %im %is\n\n", t2.hora, t2.minuto, t2.segundo);
    } 
    else if (rc == 0)
    {
        printf("\nAs tarefas demoraram o mesmo tempo, durando %ih %im %is\n\n", t1.hora, t1.minuto, t1.segundo);
    }

    return 0;
}