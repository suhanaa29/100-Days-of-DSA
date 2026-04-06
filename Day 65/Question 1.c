/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.*/

def has_cycle(adj):
    visited = set()

    def dfs(v, parent):
        visited.add(v)
        for neighbor in adj.get(v, []):
            if neighbor not in visited:
                if dfs(neighbor, v):
                    return True
            # Found a visited node that isn't the parent -> Cycle!
            elif neighbor != parent:
                return True
        return False

    for node in adj:
        if node not in visited:
            if dfs(node, -1):  # -1 represents no parent for root
                return "YES"
    return "NO"
