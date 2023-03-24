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

int main(){
    STACK S1, S2;
    int m, n;
    clearStack(&S1);
    clearStack(&S2);
    int over = 0;
    if(!isFull(&S1)) Push(&S1, 5);
    if(!isFull(&S2)) Push(&S2, 4);
    do {
        if(!isEmpty(&S1)) m = Pop(&S1);
        if(!isEmpty(&S2)) n = Pop(&S2);
        if (m == n || n == 0){
            over++;
        }
        else {
            if(!isFull(&S1)) Push(&S1, m - 1);
            if(!isFull(&S1)) Push(&S1, m - 1);
            if(!isFull(&S2)) Push(&S2, n - 1);
            if(!isFull(&S2)) Push(&S2, n);
        }
    }while(!isEmpty(&S1));
    printf("Result: %d\n", over);
    return 0;
}