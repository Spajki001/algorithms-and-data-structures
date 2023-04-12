#ifndef LV3_STACK_H
#define LV3_STACK_H

typedef struct stack{
    int data[100];
    int sp;
} STACK;

int clearStack(STACK *s);
int isEmpty(STACK *s);
int isFull(STACK *s);
int Push(STACK *s, int data);
int Pop(STACK *s);
int povrh_stack(int n, int m);

#endif //LV3_STACK_H