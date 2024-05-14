#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <errno.h> 

struct Queue {
    int *elements;
    int top;
    int rear;
    int length;
};


bool is_full(struct Queue *queue) {

    return queue->rear - queue->top == queue->length;
}

bool is_empty(struct Queue *queue) {
    return queue->rear == queue->top;
}

void enqueue(struct Queue *queue, int element) {

    if (is_full(queue)) {
        perror("Queue is full");
        exit(-1);
    }

    queue->elements[queue->rear % queue->length] = element; 
    queue->rear += 1;
}

void dequeue(struct Queue *queue) {

    if (is_empty(queue)) {
        perror("Queue is empty");
        exit(-1);
    }

    queue->elements[queue->top % queue->length] = 0;
    queue->top += 1;
}

void print_queue(struct Queue *queue) {

    for (int index = queue->top; index < queue->rear; index++) {

        int position = index %queue->length;
        printf("[%d] ", queue->elements[position]);
    }
    printf("\n");
}

int main() {


    struct Queue *queue = malloc(5 * sizeof(struct Queue));
    queue->length = 5;
    queue->rear = 0;
    queue->top = 0;
    queue->elements = (int *) malloc(5 * sizeof(int));

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);

    print_queue(queue);

    free(queue);

    return 0;
}