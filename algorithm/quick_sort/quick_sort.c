#include <stdio.h>

void quick_sort(int*, int size);
void f_quick_sort(int*, int, int);
int partition(int*, int, int);

void printArray(int* a, int size) {
    for(int i = 0; i < size; i++) {
        printf("array is %d \n", a[i]);
    }
}

int main(int argc, char* argv[]) {
    // int input[] = {1, 2, 3, 4, 5, 6, 7};
    int input[] = {1, 2, 66, 4, 57, 6, 7};
    int size = sizeof(input) / sizeof(input[0]);

    printf("===== before quick sort ===== \n");
    printArray(input, size);
    printf("===== after quick sort ===== \n");
    quick_sort(input, size);
    printArray(input, size);

    return 0;
}

void quick_sort(int* origin_array, int size) {
    printf("quick_sort begin \n");
    printf("size = %d \n", size);
    f_quick_sort(origin_array, 0, size-1);
    return;
}

void f_quick_sort(int* A, int p, int r) {
    if(p >= r) 
        return;
    
    int q = partition(A, p, r);
    f_quick_sort(A, p, q-1);
    f_quick_sort(A, q+1, r);
}

int partition(int* A, int p, int r) {
    int i = p;
    int pivot = A[r];
    for(int j = p; j <= r -1; j++) {
        if(A[j] < pivot) {
            //swap A[j] & A[i]
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }
    //swap A[i] & A[pivot]
    int tmp = A[i];
    A[i] = A[r];
    A[r] = tmp;
    return i;
}
