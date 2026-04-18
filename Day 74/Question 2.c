/*Return the total number of provinces*/

void dfs(int** isConnected, int n, int* visited, int i) {
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            visited[j] = 1;
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            visited[i] = 1;
            dfs(isConnected, n, visited, i);
        }
    }

    free(visited);
    return provinces;
}
