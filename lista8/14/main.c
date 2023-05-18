#include <stdio.h>
#include <stdlib.h>

typedef struct _FRACAO {
    int numerador; int denominador;
} FRACAO;

FRACAO soma(FRACAO f1, FRACAO f2) {
    FRACAO f;
    f.numerador = f1.numerador*f2.denominador + f2.numerador*f1.denominador;
    f.denominador = f1.denominador * f2.denominador;
    return f;
}

FRACAO subtracao(FRACAO f1, FRACAO f2) {
    FRACAO f;
    f.numerador = f1.numerador*f2.denominador - f2.numerador*f1.denominador;
    f.denominador = f1.denominador * f2.denominador;
    return f;
}

FRACAO produto(FRACAO f1, FRACAO f2) {
    FRACAO f;
    f.numerador = f1.numerador * f2.numerador;
    f.denominador = f1.denominador * f2.denominador;
    return f;
}

FRACAO divisao(FRACAO f1, FRACAO f2) {
    FRACAO f;
    f.numerador = f1.numerador * f2.denominador;
    f.denominador = f1.denominador * f2.numerador;
    return f;
}


int main(void)
{
    FRACAO f1, f2, fr;

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

    fr = soma(f1, f2);
    printf("SOMA: %d / %d\n", fr.numerador, fr.denominador);
    fr = subtracao(f1, f2);
    printf("SUBTRACAO: %d / %d\n", fr.numerador, fr.denominador);
    fr = produto(f1, f2);
    printf("PRODUTO: %d / %d\n", fr.numerador, fr.denominador);
    fr = divisao(f1, f2);
    printf("DIVISAO: %d / %d\n", fr.numerador, fr.denominador);

    return 0;
}