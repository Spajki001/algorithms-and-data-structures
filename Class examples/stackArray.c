#include <stdio.h>

typedef struct stack{
    int data[100];
    int sp;
} STACK;

int clearStack(STACK *s){
    s->sp = -1;
    return 1;
}

int isEmpty(STACK *s){
    int result;
    if(s->sp == -1) result = 1;
    else result = 0;
    return result;
}

int isFull(STACK *s){
    int result;
    if(s->sp == 99) result = 1;
    else result = 0;
    return result;
}

int Push(STACK *s, int data){
    s->sp++;
    s->data[s->sp] = data;
    return 1;
}

int Pop(STACK *s){
    int result = s->data[s->sp];
    s->sp--;
    return result;
}

int printStack(STACK *s){
    int i;
    printf("\n");
    for(i = 0; i <= s->sp; i++)
        printf(" %d ", s->data[i]);
    printf("\n");
    return 1;
}

int main() {
    STACK S1;
    clearStack(&S1);
    if(!isFull(&S1)) Push(&S1, 5);
    if(!isFull(&S1)) Push(&S1, 7);
    if(!isFull(&S1)) Push(&S1, 4);
    if(!isFull(&S1)) Push(&S1, 1);
    printStack(&S1);
    if(!isEmpty(&S1)) printf("\nData from stack: %d\n", Pop(&S1));
    printStack(&S1);
    if(!isEmpty(&S1)) printf("\nData from stack: %d\n", Pop(&S1));
    printStack(&S1);
    return 0;
}
