/*Problem: Perform DFS starting from a given source vertex using recursion.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void dfs(int s, struct Node** adj, int* visited) {
    visited[s] = 1;
    printf("%d ", s);

    struct Node* temp = adj[s];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    int visited[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Adding edge u -> v
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->vertex = v;
        newNode->next = adj[u];
        adj[u] = newNode;
        
        // For undirected, add v -> u
        newNode = malloc(sizeof(struct Node));
        newNode->vertex = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s, adj, visited);
    printf("\n");

    return 0;
}
