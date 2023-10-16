#include <stdio.h>
#include <stdlib.h>

typedef struct box{
    float data;
    struct box *prev, *next;
} BOX;

int main() {
    BOX *firstBox = NULL, *lastBox = NULL, *newBox = NULL, *tempBox = NULL;
    float data;
    do {
        printf (" Enter real number (0 or less for end): ");
        scanf ("%f", &data);
        if (data > 0.00) {
            newBox = (BOX *)malloc(sizeof(BOX));
            if(newBox != NULL){
                newBox->data = data;
                newBox->prev = NULL;
                newBox->next = NULL;
                if(firstBox == NULL){
                    firstBox = newBox;
                    lastBox = newBox;
                }
                else{
                    tempBox = firstBox;
                    if(newBox->data <= tempBox->data){
                        newBox->next = firstBox;
                        tempBox->prev = newBox;
                        firstBox = newBox;
                    }
                    else{
                        while(tempBox->next != NULL){
                            if(newBox->data > tempBox->data && newBox->data <= tempBox->next->data){
                                newBox->next = tempBox->next;
                                tempBox->next->prev = newBox;
                                newBox->prev = tempBox;
                                tempBox->next = newBox;
                            }
                            tempBox = tempBox->next;
                        }
                        if(tempBox->next == NULL){
                            newBox->prev = tempBox;
                            tempBox->next = newBox;
                            lastBox = newBox;
                        }
                    }
                }
            }
        }
    } while (data > 0);
    //traversing double-linked list - from last to first
    tempBox = lastBox;
    while(tempBox != NULL){
        printf(" %f ", tempBox->data);
        tempBox = tempBox->prev;
    }
    // free memory - copy from LinkedList code
    printf("\nReleasing memory...\n");
    tempBox = firstBox;
    while(tempBox->next != NULL){
        firstBox = tempBox->next;
        free(tempBox);
        tempBox = firstBox;
    }
    free(tempBox);
    return 1;
}