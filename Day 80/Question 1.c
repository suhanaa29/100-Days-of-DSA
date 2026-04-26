/*Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices.
The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.*/

import sys

def solve():
    try:
        line = sys.stdin.readline()
        if not line:
            return
        n = int(line.strip())
    except ValueError:
        return

    inf = float('inf')
    dist = []
    
    for i in range(n):
        row = list(map(int, sys.stdin.readline().split()))
        formatted_row = []
        for j, val in enumerate(row):
            if val == -1 and i != j:
                formatted_row.append(inf)
            else:
                formatted_row.append(val)
        dist.append(formatted_row)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != inf and dist[k][j] != inf:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    for row in dist:
        print(*(val if val != inf else -1 for val in row))

if __name__ == "__main__":
    solve()
