#include <stdio.h>
#include <stdlib.h>
void shell_sort_parallel(long a[], long n){
    long i,j,k;
    long gap = 1;
    long tmp;
    while(gap*3+1 < n)
        gap = gap*3+1;

    while(gap >= 1){
        #pragma omp parallel for num_threads(thread_count) private(i,k,j)
        for(i=0; i<gap; i++){
            for(j=i; j<n-gap; j+=gap){
                k = j;
                while(k>=i && a[k] > a[k+gap]){
                    tmp = a[k];
                    a[k] = a[k+gap];
                    a[k+gap] = tmp;
                    k-= gap;
                }
            }
        }
    gap = gap / 3;
    }
}

int main() {
    long arr[] = {4, 7, 1, 3, 9, 2, 6, 8, 5};
    long n = sizeof(arr) / sizeof(arr[0]);

    //int threads_count = 4;
    //Odd_Even(arr, n);
    shell_sort_parallel(arr,n);
    //QuickSortOmp(arr,n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    return 0;
}