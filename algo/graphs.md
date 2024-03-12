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
### space (N=nodes) -> O(V)
- vis - V
- queue - V
- ans - V
- adj list - V+E
### time 
- q runs for n nodes, O(V)
- each time, loop runs on all the neightors O(2E)
- O(V + 2E)
## DFS
```cpp
void dfs(int i, vector<vector<int>>& c, vector<int> &vis) {
        vis[i]=1;
        for (int j=0; j<c.size(); j++) {
            if (c[i][j] && !vis[j]) dfs(j,c,vis);
        }
}
```
### space (N=nodes) -> O(V)
- vis - V
- queue - V
- ans - V
- adj list - V+E
### time 
- q runs for n nodes, O(V)
- each time, loop runs on all the neightors O(2E)
- O(V + 2E)
`for unidirected graph it is 2E, for directed E`

# cycle in undirected graph
```cpp
bool detect(int i, vector<int> adj[], int V) {
    vector<int> vis(V,0);
    queue<pair<int,int>> q;
    q.push({i,-1});
    vis[i]=1;
    while(!q.empty()) {
        int node = q.front().first;
        int parent  = q.front().second;
        q.pop();
        for (int x : adj[node]) {
            if (!vis[x]) {
                q.push({x, node});
                vis[x]=1;
            } else {
                if (x !=parent) return true;
            }
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
       queue<pair<int,int>>q;
        vector<int> vis(V,0);
    
        for (int i=0; i<V; i++) {
            if (detect(i,adj,V)) return true;
        }
        return false;
}
```
# Topological Sorting
- only vaild for DAG (directed acyclic graph)
- ordering such that if edges are return, so edge from u->v means u will be befoore v in the ordering
- not possible for undirected, as both u->v and v->u exist, also for cyclic there's cyclic depedency so 1->2->3->1->2->3...., is not valid
