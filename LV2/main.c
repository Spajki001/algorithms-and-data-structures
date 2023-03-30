#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct R {
    int data;
    struct R *next;
} RECORD;

//Populating the array with generated numbers
void gen_arr(int V[], int n){
    for(int i = 0; i < n; i++){
        V[i] = (int)(rand()/(double)RAND_MAX * (1000 - 1)) + 1;
    }
}

//Sequential search
void sekv_pret(int V[], int n, int x){
    int i;
    for(i = 0; i < n; i++){
        if(V[i] == x){
            printf("Number is found!\n");
            break;
        }
    }
}

void gen_list(int V[], int n, int x){
    RECORD *firstR = NULL, *newR = NULL, *tempR = NULL;
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n; i++){
        newR = (RECORD *)malloc(sizeof(RECORD));
        newR->data = V[i];
        newR->next = NULL;
        if(firstR == NULL){
            firstR = newR;
            tempR = firstR;
        }
        else {
            tempR->next = newR;
            tempR = newR;
        }
    }
    end = clock();
    printf("Gen_list time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

    start = clock();
    tempR = NULL;
    do{
        if(tempR == NULL){
            tempR = firstR;
            if(tempR->data == x){
                printf("Number is found!\n");
                break;
            }
            tempR = firstR->next;
        }
        else {
            if(tempR->data == x){
                printf("Number is found!\n");
                break;
            }
            tempR = tempR->next;
        }
    }while(tempR->next != NULL);
    end = clock();
    printf("Seq_search_list time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);
}

int main() {
    int n, x;
    clock_t start, end;
//Input the size of the array
    printf("Size of the array >> ");
    scanf("%d", &n);
    int *V = malloc(n * sizeof(int));
//Input the number to find in the array
    printf("Number for search >> ");
    scanf("%d", &x);
//Filling the array with random numbers
    start = clock();
    gen_arr(V, n);
    end = clock();
    printf("Gen_arr time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);
//Sequential search of an array
    start = clock();
    sekv_pret(V, n, x);
    end = clock();
    printf("Seq_search_arr time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);
//Generating the linked list from full array
    gen_list(V, n, x);
    free(V);
    return 0;
}
