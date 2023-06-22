#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue (insert) an element at the back of the queue
void enqueue(Queue* queue, char data) {
    Node* newNode = createNode(data);
    
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    printf("Enqueued element: %c\n", data);
}

// Function to dequeue (remove) the front element of the queue
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    
    Node* frontNode = queue->front;
    char data = frontNode->data;
    
    queue->front = frontNode->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    } else {
        queue->front->prev = NULL;
    }
    
    free(frontNode);
    
    printf("Dequeued element: %c\n", data);
}

// Function to print the queue elements
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No elements to print.\n");
        return;
    }
    
    Node* currentNode = queue->front;
    
    printf("Queue elements: ");
    while (currentNode != NULL) {
        printf("%c ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Macro for maximum queue size
#define MAX_QUEUE_SIZE 10

int main() {
    Queue* queue = createQueue();
    
    enqueue(queue, 'A');
    enqueue(queue, 'B');
    enqueue(queue, 'C');
    printQueue(queue);
    
    dequeue(queue);
    printQueue(queue);
    
    enqueue(queue, 'D');
    enqueue(queue, 'E');
    enqueue(queue, 'F');
    printQueue(queue);
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    
    enqueue(queue, 'G');
    enqueue(queue, 'H');
    enqueue(queue, 'I');
    enqueue(queue, 'J');
    enqueue(queue, 'K');
    printQueue(queue);
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    
    return 0;
}
