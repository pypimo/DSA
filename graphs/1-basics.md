# INTRO

- graphs -> vertex/nodes , edges
- undirected vs directed graph
- path in graph -> each node appears once, adjacent nodes have an edge in between = each node is reachable
- so 1-3 must hv direct edge for 1-3 to be a path
- cycles in a graph -> start from a node and end at the same node, can have multiple cycles, while visiting each node only once
- graph can be acyclic -> binary trees
- undirected cyclic graph
- directed acyclic graph (DAG)
- undiected -> degree of node D(n) = no. of edges connected to node --> total degree = 2*total edges // since evrey edge is associated with 2 nodes
- directed -> indegree, outdegree
- edge weights
  
# complexity
## adjacency list
space: O(V+E) for directed
space: O(v+2E) : for undirected

## adjacency matrix
space: O(v*V)

# REPRESENTATION
https://stackoverflow.com/questions/33499276/space-complexity-of-adjacency-list-representation-of-graph
![firefox_3Yl8OheGeq](https://github.com/pypimo/DSA/assets/60395555/8bf53b56-bc8e-4487-ae9e-5486f0b97ab0)

- adjacency matrix = O(n^2), space = N*N
```cpp
// w = weight
adj[u][v]=w, adj[v][u]=w; // for undirected graphs
adj[u][v]=w; // directed graph node from u to v
```
- adjacency list - space = O(|V| + |E|)
- Handshaking Lemma ∑deg(v)=2|E| = O(|V| + 2|E|) = O(|V| + |E|)
- worst case is O(V^2) since for a completely connected graph each node is coonected to V-1 nodes
```cpp
vector<int> arr[n+1]; // for unweighted
vector<pair<int, int>> arr[n+1];
```
