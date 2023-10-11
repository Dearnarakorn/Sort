#include <stdio.h>

long QsPartition(long a[], const long left, const long right) {
    const long pivot = a[right];
    long i = left - 1;
    for (long j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    long temp = a[i+1];
    a[i+1] = a[right];
    a[right] = temp;
    return i + 1;
}

void QsSequential(long a[], const long left, const long right) {
    if (left < right) {
        const long part = QsPartition(a, left, right);
        QsSequential(a, left, part - 1);
        QsSequential(a, part + 1, right);
    }
}

void QuickSortOmpTask(long a[], const long left, const long right, const int deep){
    if (left < right) {
        if (deep > 0) {
            const long part = QsPartition(a, left, right);
            #pragma omp task
            QuickSortOmpTask(a, part + 1, right, deep - 1);
            #pragma omp task
            QuickSortOmpTask(a, left, part - 1, deep - 1);
        } else {
            const long part = QsPartition(a, left, right);
            QsSequential(a, part + 1, right);
            QsSequential(a, left, part - 1);
        }
    }
}

void QuickSortOmp(long a[], const long n) {
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            QuickSortOmpTask(a, 0, n - 1, 15);
        }
    }
}

int main() {
    long arr[] = {4, 7, 1, 3, 9, 2, 6, 8, 5};
    long n = sizeof(arr) / sizeof(arr[0]);

    QuickSortOmp(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    return 0;
}
