/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Stack
int stack[MAX];
int top = -1;

// Visited array
int visited[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// DFS function
void DFS(struct Graph* graph, int v) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex);
        }
        temp = temp->next;
    }

    // Push to stack after visiting all neighbors
    stack[++top] = v;
}

// Topological Sort
void topologicalSort(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            DFS(graph, i);
        }
    }

    // Print stack (topological order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    
    int V = 6;
    graph->V = V;

    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }

    // Example DAG
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}