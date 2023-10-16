#include <stdio.h>

int findIndex(char node, int rows, int tree[rows][3]){
    int i = 0;
    while(tree[i][0] != node) i++;
    return i;
}

void traverse(char node, int rows, int tree[rows][3]){
   int index = findIndex(node, rows, tree);
   printf(" %c ", node); // N - print
   if(tree[index][1] != '0') traverse(tree[index][1], rows, tree); // L - print
   if(tree[index][2] != '0') traverse(tree[index][2], rows, tree); // D - print
}

int main(){
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
    traverse(tree[0][0], 15, tree);
    return 1;
}