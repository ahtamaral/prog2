#include <stdio.h>
#include <stdlib.h>

typedef
struct _TEMPO {
    int hora, minuto, segundo;
} TEMPO;

int main(void)
{
    TEMPO t1, t2, t3;
    unsigned short aux;

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

    t3.segundo = t1.segundo + t2.segundo;
    t3.minuto = 0;
    t3.hora = 0;

    if (t3.segundo >= 60)
    {
        t3.segundo = (t1.segundo + t2.segundo) % 60;
        t3.minuto += (t1.segundo + t2.segundo) / 60;
    }

    aux = t1.minuto + t2.minuto;

    if (aux >= 60)
    {
        t3.minuto += aux % 60;
        t3.hora += aux / 60;
    }

    t3.hora += t1.hora + t2.hora;

    printf("Tempo total dispendido:\n%ih %im %is\n\n", t3.hora, t3.minuto, t3.segundo);

    return 0;
}