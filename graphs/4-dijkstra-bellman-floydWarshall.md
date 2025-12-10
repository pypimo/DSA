E  = V*(V-1)  = |V^2|-|V|
does E is a much tighter bound

## shortest path in unweighed graph (directed/undirected)
- bfs from source, update node distance when encountered for the first time
  
## shortest path in weighed graph (directed/undirected)
- dijkstra
- after updating ALL djacent nodes, enter only the ones tht got updated {dist, node} in min heap
- eg we insert {10,4} but while visiting another node, we find dist to 4 is 7 so insert {7,4}
- now our algo explores adjacnt nodes for 4 twice, once with 10 dist and then with 7
- that is not needed so use sets to erase, but time complexity dosent change as erase takes log V time
- can use a queue, but it makes no greedy use of analysisng shortset distance first, so its a brute force to visit al nodes an ypdate distances (unnecessary iterations)
```
vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
        // Distance array initialized to large value
        vector<int> dist(V, 1e9);

        // Min-heap storing {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        // Distance to source is 0
        dist[src] = 0;

        // Push source into heap
        pq.push({0, src});

        // Process nodes until heap is empty
        while (!pq.empty()) {
            // Extract node with minimum distance
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip if this distance is outdated
            if (d > dist[node]) continue;

            // Traverse all adjacent neighbors
            for (auto it : adj[node]) {
                int next = it.first;
                int wt = it.second;

                // Relaxation check
                if (dist[node] + wt < dist[next]) {
                    // Update distance
                    dist[next] = dist[node] + wt;

                    // Push updated distance into heap
                    pq.push({dist[next], next});
                }
            }
        }
        return dist;
    }
};
```
```
time: O((E+V)*logV)
space: O(V)
also V^2 = E but since E can be smaller than V sometimes so (V+E)
```
https://stackoverflow.com/questions/26547816/understanding-time-complexity-calculation-for-dijkstra-algorithm

## negative edges --> bellman ford
- A shortest path in a graph with V vertices can have at most (V − 1) edges
(because if it had V edges, a vertex must repeat → that is a cycle)
- To correctly compute all shortest paths,
we must allow paths of length 1 edge, 2 edges, ..., up to (V − 1) edges.

- Each iteration of Bellman-Ford (one pass over all edges E) allows paths that are one edge longer to become correct.
- look for n-1 times (nth time to check for negative cycle, --> if changes in dist = -ve cycle):
  - n-1 times because for a nodes (if total nodes are n), a unique path can at max contain n-1 edges
  - if any more than that, then there must be a loop (a vertex is repeated) so shortest path can be shorter
  - else -ve loop
- travel all edges and update dist for each node
- final loop nth time, if any distance updates - negative cycl 
```
time: O(V*E) 
space : O(V)
```
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
