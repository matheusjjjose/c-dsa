#include <stdio.h>
#include <stdlib.h>

void fill_array(int *array, int size);
float calculate_average(int *array, int size);

int main() {

    printf("Type the number of elements: ");
    int size;
    scanf("%d", &size);
    int *array = (int *) malloc(size * sizeof(int));
    fill_array(array, size);

    float average = calculate_average(array, size);
    
    printf("The average is %.2f\n", average);
    free(array);
    return 0;
}

void fill_array(int *array, int size) {

    for (int i=0; i < size; i++) {

        printf("Value: ");
        scanf("%d", &array[i]);
    }
}

float calculate_average(int *array, int size) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(array + i);
    }

    float average = sum / size;
    return average;
}