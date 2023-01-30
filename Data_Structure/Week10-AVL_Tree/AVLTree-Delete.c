#include <stdio.h>
#include <stdlib.h>

typedef struct root
{
    int data;
    int height;
    struct root* left;
    struct root* right; 
}AVLTREE;

AVLTREE *newNode(int data){
    AVLTREE *p = (AVLTREE*)malloc(sizeof(struct root));
    p->data = data;
    p->left = p->right = NULL;
    p->height = 0;
    
    return p;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

int height(AVLTREE *r){
    if (r == NULL)
        return -1;
    return r->height;
}

AVLTREE *rightRotate(AVLTREE *z){
    AVLTREE *y = z->left;
    z->left = y->right;
    y->right = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLTREE *leftRotate(AVLTREE *z){
    AVLTREE *y = z->right;
    z->right = y->left;
    y->left = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLTREE *rightLeftRotate(AVLTREE *z){
    z->right = rightRotate(z->right);
    return leftRotate(z);
}

AVLTREE *leftRightRotate(AVLTREE *z){
    z->left = leftRotate(z->left);
    return rightRotate(z);
}

int getBalance(AVLTREE *r){
    if (r == NULL)
        return 0;
    return height(r->left) - height(r->right);
}

AVLTREE *insertToAVL(AVLTREE *root, int x){
    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insertToAVL(root->left, x);
    else if (x > root->data)
        root->right = insertToAVL(root->right, x);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

 // if (balance > 1 && getBalance(root->left) >= 0)
    if (balance > 1 && x < root->left->data)
        return rightRotate(root);
    
    if (balance > 1 && x > root->left->data)
        return leftRightRotate(root);
 
    if (balance < -1 && x > root->right->data)
        return leftRotate(root);
 
    if (balance < -1 && x < root->right->data)
        return rightLeftRotate(root);
 
    return root;
}

void inOrder(AVLTREE *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d-%d ", root->data, root->height);
        inOrder(root->right);
    }
}

AVLTREE *destroy(AVLTREE *root){
    if (root == NULL)
        return NULL;

    destroy(root->left);
    destroy(root->right);

    free(root);
    return NULL;
} 

AVLTREE *insertExampleAVLTREE(AVLTREE *root){
    root = destroy(root);
    root = insertToAVL(root, 10);
    root = insertToAVL(root, 20);
    root = insertToAVL(root, 30);
    root = insertToAVL(root, 40);
    root = insertToAVL(root, 50);
    root = insertToAVL(root, 25);
    return root;
    
    /* The constructed AVL Tree would be
                30
               /  \
             20   40
            /  \     \
           10  25    50
    */
}

AVLTREE *minValueNode(AVLTREE *node) {
    AVLTREE *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

AVLTREE *deleteNode(AVLTREE *root, int x){
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
         AVLTREE *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            AVLTREE *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
  
    if (balance > 1 && getBalance(root->left) < 0)
        return leftRightRotate(root);
  
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
  
    if (balance < -1 && getBalance(root->right) > 0)
        return rightLeftRotate(root);

    return root;
}
 
int main(){
    int data,loop=1,num;
    AVLTREE *root = NULL;
    
    while (loop)
    {
        printf("\n-1 - insertExampleTree\n1 - insertToAVL\n2 - print inOrder traversals\n3 - deleteNode\n0 - Exit\n");
        scanf("%d",&data);
        switch (data)
        {
        case -1:
            root = insertExampleAVLTREE(root);
            break;
        case 1:
            printf("\nNumber :");
            scanf("%d", &num);
            root = insertToAVL(root, num);
            break;
        case 2:
            printf("\nData-Height\n");
            inOrder(root);
            printf("\n");
            break;   
        case 3:
            printf("\nNumber :");
            scanf("%d", &num);
            root = deleteNode(root, num);
            break;    
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
}