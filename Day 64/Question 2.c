/*Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1*/

typedef struct {
    int r, c;
} QueueNode;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int freshCount = 0;
    QueueNode queue[m * n];
    int front = 0, rear = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (QueueNode){i, j};
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) return 0;

    int minutes = 0;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (front < rear) {
        int size = rear - front;
        int rottedThisMinute = 0;

        for (int i = 0; i < size; i++) {
            QueueNode curr = queue[front++];
            for (int d = 0; d < 4; d++) {
                int nr = curr.r + dirs[d][0];
                int nc = curr.c + dirs[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    freshCount--;
                    queue[rear++] = (QueueNode){nr, nc};
                    rottedThisMinute = 1;
                }
            }
        }
        if (rottedThisMinute) minutes++;
    }

    return (freshCount == 0) ? minutes : -1;
}
