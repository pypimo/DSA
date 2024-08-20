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
# complexity
## adjacency list
space: O(V+E) for directed
space: O(v+2E) : for undirected

## adjacency matrix
space: O(v*V)


# misc nonsense
|V| = E  = V*(V-1)  = |V^2|-|V|
does E is a much tighter bound

bellamn ford is V*E or V^3
dijkstra = V^2
floyd warshall V^3

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
add to stack after a dfs call ends
time: O(v+2E)
space: O(V) and O(V+E) for adjaceny (ntot 2E cause its always directed)
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
## cycle in directed graph
- if i use kahn's algo and cannot travel all nodes => cycle is present
- using dfs, the root is encountered twice, cant just put an element since it might just be another path instead of a cycle

## shortest path in unweighed undirected graph
- bfs from source, update node distance when encountered for the first time
## shortest path in weighed directed graph
- dijkstra
- after updating ALL djacent nodes, enter only the ones tht got updated {dist, node} in min heap
- eg we insert {10,4} but while visiting another node, we find dist to 4 is 7 so insert {7,4}
- now our algo explores adjacnt nodes for 4 twice, once with 10 dist and then with 7
- that is not needed so use sets to erase, but time complexity dosent change as erase takes log V time
- can use a queue, but it makes no greedy use of analysisng shortset distance first, so its a brute force to visit al nodes an ypdate distances (unnecessary iterations)
```
time: O((E+V)*logV)
space: O(V)
also V^2 = E but since E can be smaller than V sometimes so (V+E)
```
https://stackoverflow.com/questions/26547816/understanding-time-complexity-calculation-for-dijkstra-algorithm

## negative edges --> bellman ford
- look for n-1 times (nth time to check for negative cycle, --> if changes in dist = -ve cycle)
- travel all edges and update dist

- final loop nth time, if any distance updates - negative cycl 
time: O(V*E) 
space : O(V)
## floyd warshall 
- multisource distance (dp kind of approach)
- try to travel via every vertex for each source and destination
- then update that cost matrix
- so `cost[src][dest] = cost[src][via] + cost[via][dest] //choose the min or originai vs this`
- set all cost[node][node]=0, all rest to infiinity
- then n edge between u->v=wt is wrriten as `cost[u][v]=wt` (if uni=directed just include cost[v][u]=wt)
```cpp
  for (via=1; via<=n; via++) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cost[i][j] = min(cost[i][j], cost[i][via]+cost[via][j]);
        }
    }
  }
```
# minimum spanning tree
--> wrnong approach (initlially i thought)
- just taking the minimum edge weights and checking if (u or v) not in visited
- and make u,v viisted and add weight
- PROBLEM: if 1,2 has edge (added) then 3,4 edge(added), but 2,3 edge never added
- but this is a CONNECTED graph --> so our algo is wrong!
## prims's  algo
- start at an arbitraary node and trave using edges to that node ONLY
- so the prioritu queue has
- WEIGHT, NODE, PARENT
- for the initial node, weight=0 node can be anything, parent is -1
- for others is node is vsisied discard and continue
- if not than insert the {node,parent} edge and add weight-> this is how yo build the mst
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  // wt, node, parent
  pq.push({0,1});
  int s=0;
  while(!pq.empty()) {
    int node = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    if (vis[node]) continue;
	// insert (node,parent) edge in mst
    s += d;
    for (auto x : adj[node]) {
      if (vis[x.first]) continue;
      pq.push({x.second, x.first});
    }
    vis[node]=1;
  }
```
time: O((V+E)*logV)
# Disjoint Sets
- using rank (somewhat similar to height of tree)
- using size (equivalent to total number of nodes)
time: O(n*log n ) if n disjoint sets
for kruskal : n*alpha(n) or n*log(n)
alpha n is amortised ie when inputs start gting large it does not go and for small unputs it grows very slowly

## By Rank
```cpp
class DisjointSet {
    vector<int> rank, parent;
    public: 
    DisjointSet(int n)  {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) {
            parent[i]=i;
        }
    }

    int findParent(int u) {
        if (u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findParent(u), ult_v = findParent(v);
        if (rank[ult_u]<rank[ult_v]) {
            // no rank increase
            parent[ult_u] = ult_v;
        } else if (sz[ult_u]>sz[ult_v]) {
            // no rank increase
            parent[ult_v] = ult_u;
        } else {
            rank[ult_u]++;
            parent[ult_v] = ult_u;
        }
    }
};
```
## By Size
```cpp
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> sz, parent;
    public: 
    DisjointSet(int n)  {
        sz.resize(n+1, 0);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) {
            parent[i]=i;
        }
    }

    int findParent(int u) {
        if (u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findParent(u), ult_v = findParent(v);
        if (sz[ult_u]<sz[ult_v]) {
            // no rank increase
            sz[ult_v]+=sz[ult_u];
            parent[ult_u] = ult_v;
        } else {
            sz[ult_u]+=sz[ult_v];
            parent[ult_v] = ult_u;
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if (ds.findParent(3)==ds.findParent(7)) cout << "Same tree\n";
    else cout << "Not same tree\n";
    ds.unionBySize(3,7);
    if (ds.findParent(3)==ds.findParent(7)) cout << "Same tree\n";
    else cout << "Not same tree\n";
    return 0;
}
```
## trick for 2d grids where disoint sets are needed
- if grid is n*m
- then let parent and ranks be of sizes n*m
- now each node instead of being a pair {i,j} with parent as {i,j}
- the node will be i*n + j with that as parent
- all nodes/cordinates are represented like thus and then worked on

# tarjan's algo (bridges)
- brdiges  = any edge when broekn down results in 2 or mre connected coponenets
- insertion times, as an increasing counter on graph dfs
- then low[] for lowest time when vis[x] found but x!=parent[node]
- actually low[] would work by comparing low[node]=min(low[node], low[x]) when dfs is complete
- but that assumes nodes are connected in sequential order like 0 -> 1 then 2 so on
- but that is not the case

# cycle detection for undirected graphs
time : O(V+2E) + O(V) (stack space) 
## using dfs
- start dfs at a node and keep track of parent
- mark neighbors visited
- if any neighbor visisted and not parent return true
- else return false
## using bfs
- start bfs at a node and keep track of parent
- mark neighbors visited
- if neighbor visisted and not parent return true

# cycle detection for directed graphs
time : O(V+2E) + O(V) (stack space) 
## using dfs
- for a cycle a node should be visited by any other node already, but it shuold also be in the same path
- so keep vis and pathVis array
- n
## using bfs
- use kahns to get topological ordering
- if size of topo < n return true (cycle present)
