#include <stdio.h>
#include <stdlib.h>
void Odd_Even_parallel(long a[], long n){
    long phase;
    long tmp,i;
    #pragma omp parallel num_threads(thread_count) \
    default(none) shared(a, n) private(i, tmp, phase)
    for(phase = 0; phase < n; phase++){
        if(phase % 2 == 0){
            #pragma omp for
            for(i = 1; i < n-1; i += 2){
                if(a[i] > a[i+1]){
                    tmp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = tmp;
                }
            }
        }
        else{
            #pragma omp for
            for (i = 0; i < n-1; i+=2){
                if(a[i] > a[i+1]){
                    tmp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = tmp;
                }
            }
        }
    }
}

int main() {
    long arr[] = {4, 7, 1, 3, 9, 2, 6, 8, 5};
    long n = sizeof(arr) / sizeof(arr[0]);

    //int threads_count = 4;
    Odd_Even(arr, n);
    //shell_sort(arr,n);
    //QuickSortOmp(arr,n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    return 0;
}
