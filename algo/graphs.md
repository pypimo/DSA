# INTRO

- graphs - vertex/nodes , edges
- undirected vs directed graph
- path in graph - each node appears once, adjacent nodes have an edge in between = each node is reachable
- so path cant be 1356 be 12 have edge, 23 have edge, 13 must hv direct edge
- cycles in a graph - start from a node and end at the same node, can have multiple cyclec
- graph can be acyclic - binary trees
- undirected cyclic graph
- directed acyclic graph (DAG)
- undiected - degree of node D(n) = no. of edges connected to node --> total degree = 2*total edges // sunce evrey edge isassciated with 2 nodes
- directed - indegree, outdegree
- edge weights

# REPRESENTATION
adjacency matrix = O(n^2), space = N*N
```cpp
// w = weight
adj[u][v]=w, adj[v][u]=w; // for undirected graphs
adj[u][v]=w; // directed graph node from u to v
```
adjacency list - space = O(2*E)
```cpp
vector<int> arr[n+1]; // for unweighted
vector<pair<int, int>> arr[n+1];
```
