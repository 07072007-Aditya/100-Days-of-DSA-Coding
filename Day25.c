/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, i, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    
    printf("Enter key to count: ");
    scanf("%d", &key);

    
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    
    printf("Number of occurrences of %d = %d\n", key, count);

    return 0;
}