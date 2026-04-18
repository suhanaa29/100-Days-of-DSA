/*Return all critical connections in the network in any order*/

#define MIN(a,b) ((a) < (b) ? (a) : (b))

struct Edge {
    int to;
    struct Edge* next;
};

void dfs(int u, int p, int* timer, int* disc, int* low, struct Edge** adj, int** res, int* resSize, int** colSizes) {
    disc[u] = low[u] = (*timer)++;
    for (struct Edge* e = adj[u]; e; e = e->next) {
        int v = e->to;
        if (v == p) continue;
        if (disc[v] == -1) {
            dfs(v, u, timer, disc, low, adj, res, resSize, colSizes);
            low[u] = MIN(low[u], low[v]);
            if (low[v] > disc[u]) {
                res[*resSize] = (int*)malloc(2 * sizeof(int));
                res[*resSize][0] = u;
                res[*resSize][1] = v;
                (*colSizes)[*resSize] = 2;
                (*resSize)++;
            }
        } else {
            low[u] = MIN(low[u], disc[v]);
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    struct Edge** adj = (struct Edge**)calloc(n, sizeof(struct Edge*));
    struct Edge* pool = (struct Edge*)malloc(2 * connectionsSize * sizeof(struct Edge));
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0], v = connections[i][1];
        pool[2 * i].to = v; pool[2 * i].next = adj[u]; adj[u] = &pool[2 * i];
        pool[2 * i + 1].to = u; pool[2 * i + 1].next = adj[v]; adj[v] = &pool[2 * i + 1];
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) disc[i] = -1;

    int** res = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    int timer = 0, resSize = 0;

    dfs(0, -1, &timer, disc, low, adj, res, &resSize, returnColumnSizes);

    *returnSize = resSize;
    free(disc);
    free(low);
    free(adj);
    return res;
}
