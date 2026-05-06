/*
Problem: Implement push and pop operations on a stack and verify stack operations.
*/

#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, i;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        if(top >= 0) {
            top--;
        }
    }

    printf("Remaining stack elements from top to bottom:\n");
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}