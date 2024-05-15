#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *array, int size);
void initialize_array(int *array, int size);
void print(int *array, int size);

int main() {
    
    int size = 10;
    int *array = (int *) malloc(size * sizeof(int));
    
    initialize_array(array, size);
    print(array, size);
    insertion_sort(array, size);
    print(array, size);

    free(array);
    return 0;
}

void initialize_array(int *array, int size) {

    srand(time(NULL));
    for (int index = 0; index < size; index++) {
        int number = rand() % 1000;
        array[index] = number;
    }
}

void insertion_sort(int *array, int size) {

    for (int i = 1; i < size; i++) {

        int key = array[i];
        int j = i - 1;

        while(key < array[j] && j >= 0) {
            
            array[j + 1] = array[j];
            j -= 1;
        }

        array[j + 1] = key;
    }
}


void print(int *array, int size) {

    for (int index = 0; index < size; index++) {
        printf("[%d] ", array[index]);
    }
    printf("\n");
}
