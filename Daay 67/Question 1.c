/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;

void addEdge(int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = adj[src];
    adj[src] = newNode;
}

void dfs(int v) {
    visited[v] = true;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(temp->dest);
        }
        temp = temp->next;
    }
    stack[++top] = v;
}

void topologicalSort(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int n = 6;
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }

    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(n);

    return 0;
}
