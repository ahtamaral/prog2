#include <stdio.h>
#include <stdlib.h>

typedef struct _FRACAO {
    int numerador; int denominador;
} FRACAO;

int main(void)
{
    FRACAO f1, f2;

    puts("Insira o numerador e o denominador da primeira fracao: ");
    scanf("%d %d", &f1.numerador, &f1.denominador);
    
    if (f1.denominador == 0)
    {
        puts("Denominador nulo. Abortando.\n");
        exit(1);
    }

    puts("Insira o numerador e o denominador da segunda fracao: ");
    scanf("%d %d", &f2.numerador, &f2.denominador);

    if (f2.denominador == 0)
    {
        puts("Denominador nulo. Abortando.\n");
        exit(1);
    }

    printf("SOMA: %d / %d\n", f1.numerador*f2.denominador + f2.numerador*f1.denominador, f1.denominador * f2.denominador);
    printf("SUBTRACAO: %d / %d\n", f1.numerador*f2.denominador - f2.numerador*f1.denominador, f1.denominador * f2.denominador);
    printf("PRODUTO: %d / %d\n", f1.numerador * f2.numerador, f1.denominador * f2.denominador);
    printf("DIVISAO: %d / %d\n", f1.numerador * f2.denominador, f1.denominador * f2.numerador);

    return 0;
}