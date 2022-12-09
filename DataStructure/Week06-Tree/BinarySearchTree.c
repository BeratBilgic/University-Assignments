#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}BTREE;

BTREE *newNode(int data);
BTREE *insert(BTREE *root, int x);
void printInorder(BTREE *root);
void printPreorder(BTREE *root);
void printPostorder(BTREE *root);

int main(){
    int key,loop=1,num;
    BTREE *root = NULL;
    
    while (loop)
    {
        printf("\n1 - insert\n2 - printInorder\n3 - printPreorder\n4 - printPostorder\n5 - print all traversals\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            printf("\nNumber :");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            printf("\nInorder - Binary Tree\n");
            printInorder(root);
            printf("\n");
            break;
        case 3:
            printf("\nPreorder - Binary Tree\n");
            printPreorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nPostorder - Binary Tree\n");
            printPostorder(root);
            printf("\n");
            break;
        case 5:
            printf("\nInorder - Binary Tree\n");
            printInorder(root);
            printf("\n");
            printf("\nPostorder - Binary Tree\n");
            printPostorder(root);
            printf("\n");
            printf("\nPreorder - Binary Tree\n");
            printPreorder(root);
            printf("\n");
            break;
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
}

BTREE *insert(BTREE *root, int x){
    if (root == NULL)
        root = newNode(x);
    else
    {
        if (x < root->data)
            root->left = insert(root->left, x);
        else
            root->right = insert(root->right, x);
    }

    return root;
}

BTREE *newNode(int data){
    BTREE *p;
    p = (BTREE*)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    
    return p;
}

//inorder left - root - right
void printInorder(BTREE *root){
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

//preorder root - left - right
void printPreorder(BTREE *root){
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

//postorder left - right - root
void printPostorder(BTREE *root){
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}