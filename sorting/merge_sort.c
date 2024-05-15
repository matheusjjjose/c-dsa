#include <stdio.h>


int main() {
    
}


void merge(int *array, int p, int q, int r) {


    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i=0; i < n1; i++) {
        L[i] = array[p + i];
    }

    for (int j=0; j< n2; j++) {
        M[j] = array[q + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            array[k] = L[i];
            i++;
        } 
        else {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {

        array[k] = M[j];
        j++;
        k++;
    }
}

void merge_sort() {
    
}