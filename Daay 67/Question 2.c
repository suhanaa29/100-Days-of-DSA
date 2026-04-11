/*Return the ordering of courses you should take to finish all courses.
If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.*/

#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node* next;
};

bool hasCycle(int u, struct Node** adj, int* visited, int* stack, int* top) {
    visited[u] = 1;
    struct Node* curr = adj[u];
    while (curr) {
        int v = curr->val;
        if (visited[v] == 1) return true;
        if (visited[v] == 0 && hasCycle(v, adj, visited, stack, top)) return true;
        curr = curr->next;
    }
    visited[u] = 2;
    stack[(*top)--] = u;
    return false;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    struct Node** adj = (struct Node**)malloc(numCourses * sizeof(struct Node*));
    for (int i = 0; i < numCourses; i++) adj[i] = NULL;

    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = v;
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* result = (int*)malloc(numCourses * sizeof(int));
    int top = numCourses - 1;

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (hasCycle(i, adj, visited, result, &top)) {
                *returnSize = 0;
                free(visited);
                for (int j = 0; j < numCourses; j++) {
                    struct Node* curr = adj[j];
                    while (curr) {
                        struct Node* tmp = curr;
                        curr = curr->next;
                        free(tmp);
                    }
                }
                free(adj);
                return NULL;
            }
        }
    }

    *returnSize = numCourses;
    free(visited);
    // Cleanup adj list before returning
    for (int i = 0; i < numCourses; i++) {
        struct Node* curr = adj[i];
        while (curr) {
            struct Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(adj);
    
    return result;
}
