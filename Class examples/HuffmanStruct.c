#include <stdio.h>
#include <string.h>

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

void traverse(int index, NODE *n, char *code){
    strcpy(n[index].code, code);
    if(n[index].left != '\0')
        traverse(findIndex(n[index].left, n), n, strcat(code, "0"));
    if(n[index].right != '\0')
        traverse(findIndex(n[index].right, n), n, strcat(code, "1"));
}

int findMinWeightNode(NODE *n, int num){
    int i = 0, j, minWeightIndex;
    float minWeight;
    while(n[i].used == 1) i++;
    if(i == num - 1) {
        return -1;
        n[i].type = 'R';
    }
    else {
        minWeight = n[i].weight;
        minWeightIndex = i;
        for(j = 0; j < num; j++){
            if(n[j].used == 0 && n[j].weight < minWeight){
                minWeight = n[j].weight;
                minWeightIndex = j;
            }
        }
        n[minWeightIndex].used = 1;
        return minWeightIndex;
    }
}

int main(){
    NODE nodes[100];
    int i = 0, min1, min2;
    float weight;
    char tag;
    do {
        printf("Outer node weight and tag: ");
        scanf("%f %c", &weight, &tag);
        if(weight > 0) {
            nodes[i].weight = weight;
            nodes[i].tag = tag;
            nodes[i].left = '\0';
            nodes[i].right = '\0';
            nodes[i].type = 'o';
            nodes[i].used = 0;
            i++;
        }
    } while(weight > 0);
    do {
        min1 = findMinWeightNode(nodes, i);
        if(min1 != -1){
            min2 = findMinWeightNode(nodes, i);
            i++;
            nodes[i].weight = nodes[min1].weight + nodes[min2].weight;
            nodes[i].used = 0;
            nodes[i].type = 'i';
            nodes[i].left = nodes[min1].tag;
            nodes[i].right = nodes[min2].tag;
        }
        else{
            nodes[min1].type = 'R';
        }
    } while(min1 != -1);
    traverse(i, nodes, "");
    for(int j = 0; j < i; j++){
        printf("%c ", nodes[j].tag);
    }
    return 1;
}