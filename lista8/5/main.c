#include <stdio.h>
#include <stdlib.h>

typedef
struct _TEMPO {
    int hora, minuto, segundo;
} TEMPO;

int main(void)
{
    TEMPO t1, t2;

    /*O padrao para essa variavel sera o seguinte:
    maior = 1 caso t1 seja maior
    maior = -1 caso t2 seja maior
    maior = 0 caso t1 seja igual a t2
    */
    short maior;

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

    if (t1.hora > t2.hora)
    {
        maior = 1;
    }
    else if (t1.hora < t2.hora)
    {
        maior = -1;
    }
    else 
    {
        if (t1.minuto > t2.minuto)
        {
            maior = 1;
        }
        else if (t1.minuto < t2.minuto)
        {
            maior = -1;
        }
        else 
        {
            if (t1.segundo > t2.segundo)
            {
                maior = 1;
            }
            else if (t1.segundo < t2.segundo)
            {
                maior = -1;
            }
            else 
            {
                maior = 0;
            }
        }
    }


    if (maior == 1)
    {
        printf("\nA primeira tarefa foi mais longa, durando %ih %im %is\n\n", t1.hora, t1.minuto, t1.segundo);
    }
    else if (maior == -1)
    {
        printf("\nA segunda tarefa foi mais longa, durando %ih %im %is\n\n", t2.hora, t2.minuto, t2.segundo);
    } 
    else if (maior == 0)
    {
        printf("\nAs tarefas demoraram o mesmo tempo, durando %ih %im %is\n\n", t1.hora, t1.minuto, t1.segundo);
    }

    return 0;
}