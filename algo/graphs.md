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
void bfs( int node, vector<int> adj[]) {
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
## using bfs
```cpp
 bool bfs(vector<int> adj[], int node, vector<int>&vis, queue<pair<int,int>>& q) {
        q.push({node,-1});
        while(!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            vis[curr]=1;
            q.pop();
            for (auto x : adj[curr]) {
                if (!vis[x]) {
                    vis[x]=1;
                    q.push({x, curr});
                } else if (x != parent)
                  return true;
            }
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        // true when same node visited
        // false otherwise
        // check if visited and not a parent
        queue<pair<int,int>> q;
        
        vector<int> vis(V,0);
        for (int i=0; i<V; i++) {
            if (!vis[i] && bfs(adj, i, vis,q)) return true;
        }
        return false;
    }
```
- if a single vis array then 1->2->3 trverssed (no cycle)
- if (-1->)4->2, then vis checks that 2 can traverse to 3, and 3 is not a parent thus cycle
- but that is false, there is no cycle
## using dfs
# Topological Sorting
- only vaild for DAG (directed acyclic graph)
- ordering such that if edges are return, so edge from u->v means u will be befoore v in the ordering
- not possible for undirected, as both u->v and v->u exist, also for cyclic there's cyclic depedency so 1->2->3->1->2->3...., is not valid

## using dfs
## using bfs - Kahn's algo
- normal vis bfs technique fails..eg edges 0->1, 0->2, 1->2,
- then 0 just marks 1,2 visited in no particular order, thus need for indegree, only when indegree is 0 do we insert it in queue
```cpp
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int V) {
    vector<int> adj[V];
    int indeg[V] = {0};
    queue<int>q;
    vector<int> ans;

    for (auto x : graph) {;
        adj[x[0]].push_back(x[1]);
        indeg[x[1]]++;
    }
    
    for (int i=0; i<V; i++) {
        if (!indeg[i]) q.push(i);
    }

    while(!q.empty()) {
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for (auto x : adj[curr]) {
            indeg[x]--;
            if (!indeg[x]) q.push(x);
        }  
    }
    // for (auto x : ans) cout << x << " ";

    return ans;
}
``` 
