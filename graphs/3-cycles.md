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


<hr>

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
- if a neighbor is already vis and path vis and not the parent -> return true (cycle present)
- when dfs ends set pathVis to 0
- return false
## using bfs
- use kahns to get topological ordering
- if size of topo < n return true (cycle present)
