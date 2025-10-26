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

<hr>

# Kruskal's Algo
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

    void unionByRank(int u, int v) {
        int ult_u = findParent(u), ult_v = findParent(v);
        if (rank[ult_u]<rank[ult_v]) {
            // no rank increase
            parent[ult_u] = ult_v;
        } else if (rank[ult_u]>rank[ult_v]) {
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
## Flatten 2D array
- if grid is n*m
- then let parent and ranks be of sizes n*m
- now each node instead of being a pair {i,j} with parent as {i,j}
- the node will be i*m + j with that as parent 
- all nodes/cordinates are represented like thus and then worked on
