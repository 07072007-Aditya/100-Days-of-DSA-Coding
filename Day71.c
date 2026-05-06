/*
Problem Statement
Implement a hash table using quadratic probing with formula:
*/
#include <stdio.h>
#define SIZE 100

int table[SIZE];

// Initialize hash table
void init(int m) {
    for(int i = 0; i < m; i++) {
        table[i] = -1; // -1 means empty
    }
}

// Quadratic probing insert
void insert(int key, int m) {
    int h = key % m;

    for(int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if(table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
    printf("Hash Table Overflow\n");
}

// Search using quadratic probing
int search(int key, int m) {
    int h = key % m;

    for(int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if(table[idx] == -1)
            return 0; // not found

        if(table[idx] == key)
            return 1; // found
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    init(m);

    scanf("%d", &q);   // number of queries

    while(q--) {
        char op;
        int x;
        scanf(" %c %d", &op, &x);

        if(op == 'I') {
            insert(x, m);
        }
        else if(op == 'S') {
            if(search(x, m))
                printf("Found\n");
            else
                printf("Not Found\n");
        }
    }

    return 0;
}