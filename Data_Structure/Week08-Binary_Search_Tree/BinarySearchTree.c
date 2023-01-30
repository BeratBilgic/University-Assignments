#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}BST;

BST *newNode(int data);
BST *insert(BST *root, int x);
BST *insertExampleTree(BST *root);
void printAllTraversals(BST *root);
void printInorder(BST *root);
void printPreorder(BST *root);
void printPostorder(BST *root);
int countLeaf(BST *root);
int sumOfNode(BST *root);
int findDepthByNode(BST *root, int x);
int findTreeHeight(BST *root);
int findHeightByNode(BST *root, int x);

int main(){
    int key,loop=1,num;
    BST *root = NULL;
    
    while (loop)
    {
        printf("\n-1 - insertExampleTree\n1 - insert\n2 - print all traversals\n3 - countLeaf\n4 - sumOfNode\n");
        printf("5 - findDepthByNode\n6 - findTreeHeight\n7 - findHeightByNode\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case -1:
            root = insertExampleTree(root);
            break;
        case 1:
            printf("\nNumber :");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            printAllTraversals(root);
            break;
        case 3:
            printf("Number of leaves: %d\n", countLeaf(root));
            break;
        case 4:
            printf("Sum of node->data: %d\n", sumOfNode(root));
            break;
        case 5:
            printf("\nNumber :");
            scanf("%d", &num);
            printf("Depth of %d: %d\n",num ,findDepthByNode(root, num));
            break;
        case 6:
            printf("Height of Tree: %d\n",findTreeHeight(root));
            break;
        case 7:
            printf("\nNumber :");
            scanf("%d", &num);
            printf("Height of %d: %d\n",num ,findHeightByNode(root, num));
            break;            
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
}

int countLeaf(BST *root){
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return countLeaf(root->left) + countLeaf(root->right); 
}

int sumOfNode(BST *root){
    if (root == NULL)
        return 0;
    else
        return sumOfNode(root->left) + sumOfNode(root->right) + root->data; 
}

int findDepthByNode(BST *root, int x){
    if (root == NULL){
        printf("There is no %d\n", x);
        return -1000;
    }
    if (root->data == x)
        return 0;
    else if (x < root->data)
        return 1 + findDepthByNode(root->left, x);
    else
        return 1 + findDepthByNode(root->right, x);
}

int findTreeHeight(BST *root){
    if (root == NULL)
        return -1;
    else {
        int left_height = findTreeHeight(root->left);
        int right_height = findTreeHeight(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int findHeightByNode(BST *root, int x){
    if (root == NULL){
        printf("There is no %d\n", x);
        return -1000;
    }
    if (root->data == x)
        return findTreeHeight(root);
    else if (x < root->data)
        return findHeightByNode(root->left, x);
    else
        return findHeightByNode(root->right, x);
}

BST *insert(BST *root, int x){
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

BST *newNode(int data){
    BST *p;
    p = (BST*)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    
    return p;
}

BST *destroy(BST *root){
    if (root == NULL)
        return NULL;
        
    destroy(root->left);
    destroy(root->right);

    free(root);
    return NULL;
} 

BST *insertExampleTree(BST *root){
    root = destroy(root);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    return root;
}

void printAllTraversals(BST *root){
    printf("\nInorder - Binary Tree\n");
    printInorder(root);
    printf("\n");
    printf("\nPostorder - Binary Tree\n");
    printPostorder(root);
    printf("\n");
    printf("\nPreorder - Binary Tree\n");
    printPreorder(root);
    printf("\n");
}

//inorder left - root - right
void printInorder(BST *root){
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

//preorder root - left - right
void printPreorder(BST *root){
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

//postorder left - right - root
void printPostorder(BST *root){
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}