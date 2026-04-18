/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.*/

def check_connected(n, edges):
    if n == 0: return "CONNECTED"
    
    adj = {i: [] for i in range(1, n + 1)}
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    
    visited = set()
    
    def dfs(node):
        visited.add(node)
        for neighbor in adj[node]:
            if neighbor not in visited:
                dfs(neighbor)
    
    dfs(1)
    
    if len(visited) == n:
        return "CONNECTED"
    else:
        return "NOT CONNECTED"

n, m = 4, 2
edges = [[1, 2], [3, 4]]
print(check_connected(n, edges))
