# Graphs

---

## Definition
A **Graph** G = (V, E) consists of:
- V: Set of vertices.
- E: Set of edges connecting pairs of vertices.

---

## Types of Graphs
- Undirected Graph: Edges have no direction.
- Directed Graph (Digraph): Edges have direction.
- Weighted Graph: Edges have weights (cost).
- Connected Graph: Path exists between all vertices.
- Complete Graph: Every vertex connected to every other.
- Sparse Graph: Few edges compared to max.
- Dense Graph: Close to max edges.

---

## Graph Representation
1. Adjacency Matrix
   - 2D matrix, size V×V.
   - A[i][j] = 1 if edge (i,j) exists.
   - Space: O(V²).
2. Adjacency List
   - Array of linked lists.
   - Space: O(V+E).

---

## Graph Traversals
### Depth First Search (DFS)
- Uses stack/recursion.
- Goes as deep as possible before backtracking.

### Breadth First Search (BFS)
- Uses queue.
- Visits neighbors first, then deeper levels.

---

## Minimum Spanning Tree (MST)
A spanning tree of a weighted graph with minimum total weight.

Algorithms:
- Prim’s Algorithm: Greedy, grows MST from one vertex.
- Kruskal’s Algorithm: Greedy, adds edges in increasing weight (union-find).

---

## Shortest Path Algorithms
1. Dijkstra’s Algorithm
   - Works for positive weights.
   - Greedy: picks min distance vertex step by step.
2. Bellman-Ford Algorithm
   - Works for negative weights also.
   - Dynamic Programming: relax edges V-1 times.
3. Floyd-Warshall
   - All-pairs shortest path.
   - O(V³).

---

## Complexity Summary
- Graph traversals (DFS/BFS): O(V+E)
- Dijkstra: O(V²) or O((V+E) log V) with priority queue.
- Kruskal: O(E log V)

---

## Applications of Graphs
- Social networks
- Maps and routing
- Computer networks
- Project scheduling (PERT, CPM)
