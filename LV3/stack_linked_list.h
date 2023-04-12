#ifndef LV3_STACK_LINKED_LIST_H
#define LV3_STACK_LINKED_LIST_H

typedef struct node_list{
    int data;
    struct node_list *next;
} NODE_LIST;

typedef struct stack_list{
    NODE_LIST *top;
} STACK_LIST;

void clearStackList(STACK_LIST *s);
int isEmptyList(STACK_LIST *s);
int PushList(STACK_LIST *s, int data);
int PopList(STACK_LIST *s);
int povrh_stack_list(int n, int m);

#endif //LV3_STACK_LINKED_LIST_H
