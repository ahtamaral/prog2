#include <stdio.h>
#include <stdlib.h>

/* Nó que representa um elemento da lista*/
typedef struct Node 
{
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

// Estrutura que representa a lista
typedef struct _FILA 
{
    Node* front;    
    Node* rear;
} FILA;

// Cria nó a partir de um caracter
Node* createNode(char data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Cria fila vazia
FILA* criaFila() 
{
    FILA* fila = (FILA*)malloc(sizeof(FILA));
    fila->front = NULL;
    fila->rear = NULL;
    return fila;
}

// Checa se fila está vazia
int isEmpty(FILA* fila) 
{
    return fila->front == NULL;
}

// Insere elemento no final da fila
void insert(FILA* fila, char data) 
{
    Node* newNode = createNode(data);
    
    if (isEmpty(fila)) 
    {
        fila->front = newNode;
        fila->rear = newNode;
    } else {
        newNode->prev = fila->rear;
        fila->rear->next = newNode;
        fila->rear = newNode;
    }
    
    printf("Inseriu elemento na fila: %c\n", data);
}

// remover elemento do inicio da fila
void remover(FILA* fila) 
{
    if (isEmpty(fila)) 
    {
        printf("Fila vazia. Nao ha elementos para remover.\n");
        return;
    }
    
    Node* frontNode = fila->front;
    char data = frontNode->data;
    
    fila->front = frontNode->next;
    
    if (fila->front == NULL) 
    {
        fila->rear = NULL;
    } else 
    {
        fila->front->prev = NULL;
    }
    
    free(frontNode);
    
    printf("removeu elemento: %c\n", data);
}

void printaFila(FILA* fila) 
{
    if (isEmpty(fila)) 
    {
        printf("Fila vazia. Nao ha elementos para printar.\n");
        return;
    }
    
    Node* currentNode = fila->front;
    
    printf("Fila: ");
    while (currentNode != NULL) 
    {
        printf("%c ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    FILA* fila = criaFila();
    
    insert(fila, 'A');
    insert(fila, 'B');
    insert(fila, 'C');
    printaFila(fila);
    puts("");

    remover(fila);
    printaFila(fila);
    puts("");

    insert(fila, 'D');
    insert(fila, 'E');
    insert(fila, 'F');
    printaFila(fila);
    puts("");

    remover(fila);
    remover(fila);
    remover(fila);
    remover(fila);
    remover(fila);
    remover(fila);
    printaFila(fila);
    puts("");
    
    insert(fila, 'G');
    insert(fila, 'H');
    insert(fila, 'I');
    insert(fila, 'J');
    insert(fila, 'K');
    printaFila(fila);
    puts("");
    
    remover(fila);
    remover(fila);
    remover(fila);
    remover(fila);
    remover(fila);
    printaFila(fila);
    puts("");
    
    return 0;
}