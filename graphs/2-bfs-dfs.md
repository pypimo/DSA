# Traversals
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
  
<hr>

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
