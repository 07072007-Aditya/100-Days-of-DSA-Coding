/*
Problem: Level Order Traversal
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue for level order traversal
struct Node* queue[100];
int front = -1, rear = -1;

// Enqueue function
void enqueue(struct Node* node)
{
    if (rear == 99)
        return;
    
    if (front == -1)
        front = 0;
    
    queue[++rear] = node;
}

// Dequeue function
struct Node* dequeue()
{
    if (front == -1 || front > rear)
        return NULL;

    return queue[front++];
}

// Level Order Traversal
void levelOrder(struct Node* root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

int main()
{


    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}