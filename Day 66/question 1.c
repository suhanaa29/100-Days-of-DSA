/*Problem: Detect cycle in directed graph using DFS and recursion stack*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool isCyclicUtil(int v, bool visited[], bool recStack[], int adj[MAX][MAX], int V) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i] && isCyclicUtil(i, visited, recStack, adj, V))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool isCyclic(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack, adj, V))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4;
    int adj[MAX][MAX] = {0};

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;

    if (isCyclic(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
