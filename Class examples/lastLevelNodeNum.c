#include <stdio.h>

typedef struct Node {
    char tag, left, right, type;
    float weight, used;
    char code[100];
} NODE;

int findIndex(char tag, NODE *n){
    int i = 0;
    while(n[i].tag != tag) i++;
    return i;
}

void countLastLevelNodes(int index, NODE *n, int level, int targetLevel, int *q){
    if(level == targetLevel && n->type == 'o') (*q)++;
    // print for NLD
    if(n[index].left != '\0')
        countLastLevelNodes(findIndex(n[index].left, n), n, level++, targetLevel, q);
    // print for LND
    if(n[index].right != '\0')
        countLastLevelNodes(findIndex(n[index].right, n), n, level++, targetLevel, q);
    // print for LDN
}

int main(){
    NODE nodes[100];
    int quantity = 0;
    // ...
    countLastLevelNodes(0, nodes, 0, 4, &quantity);
}