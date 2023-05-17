#include <stdio.h>
#include <math.h>

typedef struct _PONTO {
    float x, y;
} PONTO;

typedef struct _CIRCUNFERENCIA {
    float raio;
    PONTO centro;
} CIRCUNFERENCIA;

int main(void)
{
    CIRCUNFERENCIA c;
    PONTO p;

    float distancia;

    printf("Entre com as coordenadas do ponto p:\n");
    scanf("%f %f", &p.x, &p.y);

    printf("Entre com as coordenadas do centro do circulo:\n");
    scanf("%f %f", &c.centro.x, &c.centro.y);

    printf("Entre com o raio do circulo:\n");
    scanf("%f", &c.raio);

    distancia = sqrt(pow(p.x - c.centro.x, 2) + pow(p.y - c.centro.y, 2));

    if (distancia < c.raio)
    {
        printf("O ponto esta contido dentro da circunferencia.\n");
    } 
    else 
    {
        printf("O ponto nao esta contido dentro da circunferencia.\n");
    }

    return 0;
}