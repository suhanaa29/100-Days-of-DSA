/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    indegree[v]++;
}

void topologicalSort(int n) {
    int result[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->dest;
            indegree[v]--;
            if (indegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != n) {
        printf("Graph has a cycle!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int n = 6;
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
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
