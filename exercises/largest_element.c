#include <stdio.h>
#include <stdlib.h>

void fill_array(int *array, int size);
int get_largest(int *array, int size);

int main() {

    printf("Type the number of elements: ");
    int size;
    scanf("%d", &size);
    int *array = (int *) calloc(size, sizeof(int));

    fill_array(array, size);

    int largest = get_largest(array, size);

    printf("The largest element in array is %d\n", largest);
    free(array); 
    return 0;
}

void fill_array(int *array, int size) {

    for (int i=0; i < size; i++) {

        printf("Value: ");
        scanf("%d", &array[i]);
    }
}

int get_largest(int *array, int size) {

    int largest = array[0];

    for (int i=1; i < size; i++) {

        if (array[i] > largest) {
            largest = array[i];
        }
    }

    return largest;
}