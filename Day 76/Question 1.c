/*Problem Statement
Using DFS or BFS, count number of connected components.*/

def count_components(n, edges):
    adj = {i: [] for i in range(1, n + 1)}
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    
    visited = [False] * (n + 1)
    count = 0
    
    def dfs(node):
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                dfs(neighbor)
    
    for i in range(1, n + 1):
        if not visited[i]:
            count += 1
            dfs(i)
            
    return count

n, m = 6, 3
edges = [[1, 2], [2, 3], [5, 6]]
print(count_components(n, edges))
