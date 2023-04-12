#include "stack.h"

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

// Calculate n over m using stacks
int povrh_stack(int n, int m) {
    STACK S1, S2;
    clearStack(&S1);
    clearStack(&S2);
    int result = 0;
    if(!isFull(&S1)) Push(&S1, n);
    if(!isFull(&S2)) Push(&S2, m);
    do {
        if(!isEmpty(&S1)) n = Pop(&S1);
        if(!isEmpty(&S2)) m = Pop(&S2);
        if (n == m || m == 0){
            result++;
        }
        else {
            if(!isFull(&S1)) Push(&S1, n - 1);
            if(!isFull(&S1)) Push(&S1, n - 1);
            if(!isFull(&S2)) Push(&S2, m - 1);
            if(!isFull(&S2)) Push(&S2, m);
        }
    }while(!isEmpty(&S1));
    return result;
}