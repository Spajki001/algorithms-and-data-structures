#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Populating the array with generated numbers
void gen_arr(double V[], int n, double dg, double gg){
    for(int i = 0; i < n; i++){
        V[i] = ((double)rand()/(double)RAND_MAX * (gg - dg)) + dg;
    }
    printf("\nGen_arr is finished!\n");
}

//Sequential search
int sekv_pret(double V[], int n, double x){
    int i, index;
    for(i = 0; i < n; i++){
        if(V[i] == x){
            index = i;
            break;
        }
    }
    if(i == n){
        printf("\nSekv_pret is finished with return -1!\n");
        return -1;
    }
    else{
        printf("\nSekv_pret is finished with index return %d!\n", index);
        return index;
    }
}

//Array sorting
void sort(double V[], int low, int high){
    if (low < high) {
        // Partition the array
        double pivot = V[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (V[j] < pivot) {
                i++;
                double temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
        }
        double temp = V[i+1];
        V[i+1] = V[high];
        V[high] = temp;

        // Recursively sort the sub-arrays
        sort(V, low, i);
        sort(V, i+2, high);
    }
}

//Binary search
int bin_pret(double V[], int n, double x){
    int i = 0, mid;
    while (i <= n) {
        mid = i + (n - i) / 2;
        if (V[mid] == x) {
            printf("\nBin_pret is finished with index return %d!\n", mid);
            return mid;
        } else if (V[mid] < x) {
            i = mid + 1;
        } else {
            n = mid - 1;
        }
    }
    printf("\nBin_pret is finished with return -1!\n");
    return -1;
}

int main() {
    int n;
    double dg, gg, x;
    char choice;
    clock_t start, end;
//Input the size of the array
    printf("Size of the array >> ");
    scanf("%d", &n);
//Input the min and max numbers for random number generator
    printf("min, max >> ");
    scanf("%lf, %lf", &dg, &gg);
//Input the number to find in the array
    printf("Number for search >> ");
    scanf("%lf", &x);
//Print out the array yes/no
    printf("Print out the array Y/N? >> ");
    scanf("%c", &choice);
    getchar();
    double *V = malloc(n * sizeof(double));

//Filling the array with random numbers
    start = clock();
    gen_arr(V, n, dg, gg);
    end = clock();
    printf("Gen_arr time %lf\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

//Print out the unsorted array
    if(choice == 'Y' || choice == 'y'){
        printf("\nUnsorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%.2f ", V[i]);
        }
        printf("\n");
    }

//Sequential search
    start = clock();
    sekv_pret(V, n, x);
    end = clock();
    printf("Sekv_pret time %lf\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

//Array sorting algorithm
    start = clock();
    sort(V, 0, n - 1);
    printf("\nSort is finished!\n");
    end = clock();
    printf("Sort time %lf\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

//Binary search
    start = clock();
    bin_pret(V, n, x);
    end = clock();
    printf("Bin_pret time %lf\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

//Print out the sorted array
    if(choice == 'Y' || choice == 'y'){
        printf("\nSorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%.2f ", V[i]);
        }
    }
    system("pause");
    free(V);
    return 0;
}
