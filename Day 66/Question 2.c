/*Return true if you can finish all courses. Otherwise, return false*/

#include <stdbool.h>
#include <stdlib.h>

bool hasCycle(int v, int* adj[], int adjSize[], bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < adjSize[v]; i++) {
        int neighbor = adj[v][i];
        if (!visited[neighbor]) {
            if (hasCycle(neighbor, adj, adjSize, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* adj[numCourses];
    int adjSize[numCourses];
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(sizeof(int) * prerequisitesSize); 
        adjSize[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        adj[pre][adjSize[pre]++] = course;
    }

    bool visited[numCourses];
    bool recStack[numCourses];
    for (int i = 0; i < numCourses; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (hasCycle(i, adj, adjSize, visited, recStack)) {
                for (int j = 0; j < numCourses; j++) free(adj[j]);
                return false;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) free(adj[i]);
    return true;
}
