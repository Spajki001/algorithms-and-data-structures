#include <stdio.h>
#include <stdlib.h>

typedef struct R {
    int data;
    struct R *next;
} RECORD;

int main(){
    RECORD *firstR = NULL, *newR = NULL, *tempR = NULL;
    int num;
    do {
        printf("Input data (0 for end): ");
        scanf("%d", &num);
        if(num > 0){
            newR = (RECORD *)malloc(sizeof(RECORD));
            newR->data = num;
            newR->next = NULL;
            if(firstR == NULL){
                firstR = newR;
            }
            else {
                tempR = firstR;
                if(newR->data <= firstR->data){
                    newR->next = firstR;
                    firstR = newR;
                }
                else {
                    while(tempR->next != NULL){
                        if(newR->data > tempR->data && newR->data <= tempR->next->data){
                            newR->next = tempR->next;
                            tempR->next = newR;
                            break;
                        }
                        tempR = tempR->next;
                    }
                    if(tempR->next == NULL){
                        tempR->next = newR;
                    }
                }
            }
        }
    } while(num > 0);
    tempR = firstR;
    //looping through list elements
    while(tempR != NULL){
        printf(" %d ", tempR->data);
        tempR = tempR->next;
    }
    //free memory
    printf("\nReleasing memory...\n");
    tempR = firstR;
    while(tempR->next != NULL){
        firstR = tempR->next;
        free(tempR);
        tempR = firstR;
    }
    free(tempR);
    return 1;
}