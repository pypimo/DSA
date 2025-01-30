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

- to detect cycles, index that stack elements 1 2 3 4..., not check in adjacency matrix, if u->v and pos[u]>pos[v] cycel exists

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
