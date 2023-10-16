#include <stdio.h>

int findIndex(char node, int rows, int tree[rows][3]){
    int i = 0;
    while(tree[i][0] != node) i++;
    return i;
}

typedef struct stack{
    char data[100];
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

int Push(STACK *s, char data){
    s->sp++;
    s->data[s->sp] = data;
    return 1;
}

char Pop(STACK *s){
    char result = s->data[s->sp];
    s->sp--;
    return result;
}

int printStack(STACK *s){
    int i;
    for (i = 0; i < s->sp; i++)
        printf(" %c ", s->data[s->sp]);
    printf("\n");
}

int main(){
    STACK s;
    char node;
    int index;
    int tree[][3] = {
        {'R', 'a', '0'},
        {'a', 'e', 'b'},
        {'e', 'l', 'f'},
        {'b', 'g', 'c'},
        {'l', '0', 'm'},
        {'f', '0', '0'},
        {'g', '0', 'h'},
        {'c', '0', 'd'},
        {'m', '0', '0'},
        {'h', '0', 'i'},
        {'d', 'j', '0'},
        {'i', '0', '0'},
        {'j', 'n', 'k'},
        {'n', '0', 'o'},
        {'k', '0', '0'},
        {'o', '0', '0'}
    };
    clearStack(&s);
    Push(&s, 'R');
    while(!isEmpty(&s)) {
        node = Pop(&s);
        printf(" %c ", node); // N - print
        index = findIndex(node, 15, tree);
        if(tree[index][2] != '0') Push(&s, tree[index][2]); // D - print
        if(tree[index][1] != '0') Push(&s, tree[index][1]); // L - print
    }
    return 1;
}