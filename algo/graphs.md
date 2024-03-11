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
https://stackoverflow.com/questions/33499276/space-complexity-of-adjacency-list-representation-of-graph
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
# traversals
- create a visited array (helps for both strongly connected componenets and keeping track of those in queue)
## BFS 
- keep adding level by level and mark in visited array
```cpp
void bfs( int node, int adj[]) {
    vis[node]=1;
    q.push(node);
    vector<int> ans;
    while(!q.empty) {
        int Node = q.front();
        ans.push_back(u);
        q.pop();
        for (auto x : adj[u]) {
          if (!vis[x]) {
            vis[x]=1;
            q.push(x);
          }
        }
    }
}

```
## DFS
```cpp
void dfs(int i, vector<vector<int>>& c, vector<int> &vis) {
        vis[i]=1;
        for (int j=0; j<c.size(); j++) {
            if (c[i][j] && !vis[j]) dfs(j,c,vis);
        }
}
```
