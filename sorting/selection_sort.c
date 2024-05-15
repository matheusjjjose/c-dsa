#include <stdio.h>

void selection_sort(int *array, int size);
void swap(int *smaller, int *higher);
void print(int *array, int size);

int main() {

    int size = 10;
    int array[] = {98, 155, 2, 35, 27, 13, 164, 355, 50, 17};

    print(array, size);
    selection_sort(array, size);
    print(array, size);

    return 0;
}

void selection_sort(int *array, int size) {

    for (int j = 0; j < size - 1; j++) {
        int min = j;
        for (int k = j + 1; k < size; k++) {

            if (array[k] < array[min]) {
                min = k;
            }
        }

        swap(&array[min], &array[j]);
    }
}

void swap(int *smaller, int *higher) {

    int temp = *smaller;
    *smaller = *higher;
    *higher = temp;
}

void print(int *array, int size) {

    for (int index = 0; index < size; index++) {
        printf("[%d] ", array[index]);
    }
    printf("\n");
}