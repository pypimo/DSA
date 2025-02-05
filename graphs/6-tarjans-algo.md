# tarjan's algo (bridges)
- brdiges  = any edge when broekn down results in 2 or mre connected coponenets
- insertion times, as an increasing counter on graph dfs
- then low[] for lowest time when vis[it] found but it!=parent[node]
- actually low[] would work by comparing low[node]=min(low[node], low[it]) when dfs is complete
- condition for bridge (only for parent to non-vis adj nodes after being vis) -> because parent nodes havent compleeed their dfs, so their low isnt assigned the lowest, but the children's dfs gets completed first
- we only compare after the child nodes finished dfs using low[it] > timer[node] (cant use low[it] > low[node])
```cpp
class Solution {
public:
    int timer=0;
    void dfs(int node, int parent, vector<int>& vis,  vector<int>& low, vector<int>& tim, vector<int> adj[], vector<vector<int>> &ans) {
        vis[node]=1;
        tim[node]= low[node]=timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis,low,tim, adj, ans);
                low[node] = min(low[node], low[it]);
                if (low[it] > tim[node]) ans.push_back({node, it});
                // another method
                // if (low[it] == tim[it]) ans.push_back({node, it});
                // WORKS or >= since we know low[it] will never exceed tim[it]
                
            } else low[node] = min(low[node], low[it]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0), low(n), adj[n], tim(n);
        vector<vector<int>> ans;

        for (auto nodes : connections) {
            adj[nodes[0]].push_back(nodes[1]);
            adj[nodes[1]].push_back(nodes[0]);
        }

        dfs(0, -1, vis, low,tim, adj, ans);
        
        return ans;
    }
};
```
## determining if edge is a bridge
- we only compare after the child nodes finished dfs using low[it] > timer[node] (cant use low[it] > low[node])
<br>
![note](https://github.com/user-attachments/assets/4bb841c2-5cfe-4a84-98d4-527a2697f218)

