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
```
# cycle detection for directed graphs
time : O(V+2E) + O(V) (stack space) 
## using dfs
- for a cycle a node should be visited by any other node already, but it shuold also be in the same path
- so pathVis array (pass by copy at each call) -> TLE if V+E is large since it become V+E*V
- if a neighbor is already pathVis -> return true (cycle present)
- when dfs ends set pathVis to 0
- return false
```cpp
bool dfs(int u, int parent, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
    vis[u]=1; pathVis[u]=1;
    for (int x : adj[u]) {
        if (pathVis[x]) return true;
        if (!vis[x] && dfs(x, u, adj, vis, pathVis)) return true;   
    }
    pathVis[u]=0;
    return false;
}

int check() {  
    vector<int> vis(A+1, 0), pathVis(A+1, 0);
    for (int i=2; i<=A; i++) {
        if (!vis[i] && dfs(i,-1, adj, vis, pathVis)) return 1;
    }
    return 0;
}
```
## using bfs
- use kahns to get topological ordering
- if size of topo < n return true (cycle present)
