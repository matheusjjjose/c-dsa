#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct Stack {
    int *elements;
    int top;
    int length;
};

bool is_full(struct Stack *stack) {
    return stack->top == stack->length;
}

bool is_empty(struct Stack *stack) {

    return stack->top == 0;
}

void pop(struct Stack *stack) {

    if (is_empty(stack)) {
        fprintf(stderr, "error: stack is empty\n");
        exit(-1);
    }

    stack->elements[stack->top] = 0;
    stack->top -= 1;
    
}

void push(struct Stack *stack, int element) {

    if (is_full(stack)) {
        fprintf(stderr, "error: stack is full\n");
        exit(-1);
    }
    stack->elements[stack->top] = element;
    stack->top += 1;
}

void print(struct Stack *stack) {

    for (int index = 0; index < stack->top; index++) {

        printf("[%d] ", stack->elements[index]);
    }
    printf("\n");
}


int main() {

    struct Stack *stack = malloc(2 * sizeof(struct Stack));
    stack->top = 0;
    stack->length = 5;
    stack->elements = (int *) malloc(2 * sizeof(int));

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    pop(stack);
    pop(stack);

    print(stack);

    free(stack->elements);
    free(stack);
    return 0;
}