/*
Problem: Count Nodes in Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("The linked list is empty.\n");
        printf("Number of nodes: 0\n");
        return 0;
    }

    // Input node values
    printf("Enter %d values: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int result = countNodes(head);

    // Output result
    printf("Number of nodes in the linked list: %d\n", result);

    return 0;
}