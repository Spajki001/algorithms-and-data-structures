#include <stdlib.h>
#include "stack_linked_list.h"

void clearStackList(STACK_LIST *s){
    NODE_LIST *current = s->top;
    while(current != NULL){
        NODE_LIST *temp = current;
        current = current->next;
        free(temp);
    }
    s->top = NULL;
}

int isEmptyList(STACK_LIST *s){
    return s->top == NULL;
}

int PushList(STACK_LIST *s, int data){
    NODE_LIST *newNode = (NODE_LIST *)malloc(sizeof(NODE_LIST));
    if(newNode == NULL) return 0;
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    return 1;
}

int PopList(STACK_LIST *s){
    if(isEmptyList(s)) return -1;
    int result = s->top->data;
    NODE_LIST *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return result;
}

int povrh_stack_list(int n, int m) {
    STACK_LIST S1, S2;
    S1.top = NULL;
    S2.top = NULL;
    int result = 0;
    if(PushList(&S1, n)) {}
    if(PushList(&S2, m)) {}
    do {
        if(!isEmptyList(&S1)) n = PopList(&S1);
        if(!isEmptyList(&S2)) m = PopList(&S2);
        if (n == m || m == 0){
            result++;
        }
        else {
            if(PushList(&S1, n - 1)) {}
            if(PushList(&S1, n - 1)) {}
            if(PushList(&S2, m - 1)) {}
            if(PushList(&S2, m)) {}
        }
    }while(!isEmptyList(&S1));
    clearStackList(&S1);
    clearStackList(&S2);
    return result;
}
