#include <stdio.h>
#include <stdlib.h>

typedef struct Record{
    int data;
    struct Record *prev, *next;
}RECORD;

int main(){
    RECORD *first = NULL, *last = NULL, *tempStart = NULL, *temp = NULL, *tempEnd = NULL, *newR;
    int i, n, val;
    printf("Number of elements >> ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Value >> ");
        scanf("%d", &val);
        newR = (RECORD *)malloc(sizeof(RECORD));
        newR->data = val;
        newR->prev = NULL;
        newR->next = NULL;
        if(first == NULL){
            first = last = newR;
        }
        else{
            last->next = newR;
            newR->prev = last;
            last = newR;
        }
    }
    printf("\n");
    printf("New value >> ");
    scanf("%d", &val);
    newR = (RECORD *)malloc(sizeof(RECORD));
    newR->data = val;
    newR->prev = NULL;
    newR->next = NULL;

    tempStart = first;
    tempEnd = last;
    if(tempStart == tempEnd){
        if(tempStart == NULL){
            tempStart = tempEnd = newR;
        }
        else{
            first->next = newR;
            newR->prev = first;
            last = newR;
        }
    }
    else{
        while(tempStart != tempEnd){
            tempStart = tempStart->next;
            if(tempStart == tempEnd){
                tempStart = tempStart->prev;
                tempStart->next = newR;
                newR->prev = tempStart;
                newR->next = tempEnd;
                tempEnd->prev = newR;
                break;
            }
            tempEnd = tempEnd->prev;
            if(tempStart == tempEnd){
                tempEnd = tempEnd->next;
                tempStart->next = newR;
                newR->prev = tempStart;
                newR->next = tempEnd;
                tempEnd->prev = newR;
                break;
            }
        }
    }
    temp = first;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = first;
    while(temp->next != NULL){
        first = temp->next;
        free(temp);
        temp = first;
    }
    free(first);
    first = NULL;
    return 1;
}