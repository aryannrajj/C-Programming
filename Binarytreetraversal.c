#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNode(int val)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertNode(struct node *root, int val)
{
    if (root == NULL)
        return getNode(val);
    if (root->key < val)
        root->right = insertNode(root->right, val);
    if (root->key > val)
        root->left = insertNode(root->left, val);
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

int main()
{
    struct node *root = NULL;
    int data;
    do
    {
        printf("\n\n choose: ");
        printf("\n1. Insert a new node in the Binary Tree. \n");
        printf("\n2. Binary Tree(via Inorder Traversal).\n");
        printf("\n3. Binary Tree(via Preorder Traversal).\n");
        printf("\n4. Binary Tree(via Postorder Traversal).\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be inserted\n");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("\nInorder Traversal:\n");
            inorder(root);
            break;
        case 3:
            printf("\nPreorder Traversal:\n");
            preorder(root);
            break;
        case 4:
            printf("\nPostorder Traversal:\n");
            postorder(root);
            break;
        default:
            printf("Wrong Entry\n");
            exit(0);
        }

    } while (1);
    return 0;
}