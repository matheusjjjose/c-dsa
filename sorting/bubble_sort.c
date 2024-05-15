#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initialize_array(int *array, int *size, int capacity);
void bubble_sort(int *array, int *size);
void print(int *array, int *size);

int main() {

    int capacity = 10;
    int *size = malloc(sizeof(int));
    int *array = (int *) malloc(capacity * sizeof(int));
    *size = 0;
    
    initialize_array(array, size, capacity);
    print(array, size);
    bubble_sort(array, size);

    print(array, size);    

    free(size);
    free(array);
    return 0;
}

void initialize_array(int *array, int *size, int capacity) {

    srand(time(NULL));
    for (int index = 0; index < capacity; index++) {
        int number = rand() % 1000;
        array[index] = number;
        *size += 1;
    }
}

void bubble_sort(int *array, int *size) {

    for (int i = 0; i < *size - 1; i++) {
        for (int j = 0; j<*size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

void print(int *array, int *size) {

    for (int index = 0; index < *size; index++) {
        printf("[%d] ", array[index]);
    }
    printf("\n");
}