/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    
    printf("Doubly Linked List (Forward): ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}