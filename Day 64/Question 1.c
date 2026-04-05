/*Problem: Perform BFS from a given source using queue.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void bfs(int s, struct Node** adj, int n) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int queue[n];
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->vertex = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = malloc(sizeof(struct Node));
        newNode->vertex = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    scanf("%d", &s);
    bfs(s, adj, n);

    return 0;
}
