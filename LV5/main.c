#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_arr(int V[], int n){
    for(int i = 0; i < n; i++){
        V[i] = (int)(rand()/(int)RAND_MAX * (1000 - 1)) + 1;
    }
}

// Function to swap the position of two elements

void swap(int* a, int* b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int *V, int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(V, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&V[0], &V[i]);

        // Heapify root element to get highest element at
        // root again
        heapify(V, i, 0);
    }
}

void swap_bubble(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int *V, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (V[j] > V[j + 1])
                swap_bubble(&V[j], &V[j + 1]);
}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int *V, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(V, l, m);
        mergeSort(V, m + 1, r);

        merge(V, l, m, r);
    }
}

int main() {
    int n;
    clock_t start, end;
    printf("Size of the array >> ");
    scanf("%d", &n);
    int *V = malloc(n * sizeof(int));
    gen_arr(V, n);
    start = clock();
    bubbleSort(V, n);
    end = clock();
    printf("Bubble_sort time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

    start = clock();
    heapSort(V, n);
    end = clock();
    printf("Heap_sort time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

    start = clock();
    mergeSort(V,0,n);
    end = clock();
    printf("Merge_sort time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);
    return 0;
}
