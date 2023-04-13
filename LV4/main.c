#include <stdio.h>
#include <stdlib.h>

typedef struct cvor{
    char x;
    struct cvor *left;
    struct cvor *right;
}CVOR;

CVOR *nadji_p(CVOR *root, char x){
    CVOR *current = root;
    CVOR *parent = NULL;
    int found = 0;
    while(!found){
        if(current->x == x)
            return NULL;
        else {
            parent = current;
            if(x < current->x)
                if(current->left != NULL)
                    current = current->left;
                else
                    found = -1;
            else if(x > current->x){
                if(current->right != NULL)
                    current = current->right;
                else
                    found = -1;
            }
        }
    }
    return parent;
}

void dodaj_p(CVOR *root, char x){
    CVOR *parent;
    parent = nadji_p(root, x);
    if(!parent)
        return;
    else {
        CVOR *n = (CVOR*)malloc(sizeof(CVOR));
        n->x = x;
        n->left = NULL;
        n->right = NULL;
        if(x < parent->x){
            if(parent->left == NULL){
                parent->left = n;
            }
            else {
                parent->left->right = n;
            }
        }
        else {
            if(parent->right == NULL){
                parent->right = n;
            }
            else {
                parent->right->left = n;
            }
        }
    }
}

void preorder(CVOR *root) {
    if (root == NULL) return;
    printf("%c ", root->x);
    preorder(root->left);
    preorder(root->right);
}

void inorder(CVOR *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->x);
    inorder(root->right);
}

void postorder(CVOR *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->x);
}

int main() {
    CVOR *cvor = (CVOR*)malloc(sizeof(CVOR));
    cvor->x = 'm';
    cvor->left = NULL;
    cvor->right = NULL;
    char letter[10] = {'a', 't', 'e', 'o', '_', 's', 'p', 'j', 'i', 'c'};
    for(int i = 0; i < 10; i++){
        dodaj_p(cvor, letter[i]);
    }
    printf("Preorder (NLD): ");
    preorder(cvor);
    printf("\n");
    printf("Inorder (LND): ");
    inorder(cvor);
    printf("\n");
    printf("Postorder (LDN): ");
    postorder(cvor);
    printf("\n");
    return 0;
}
