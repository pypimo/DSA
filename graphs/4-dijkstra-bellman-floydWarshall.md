## complexity
|V| = E  = V*(V-1)  = |V^2|-|V|
does E is a much tighter bound

- bellamn ford is V*E or V^3
- dijkstra = V^2
- floyd warshall V^3

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
time: O((E+V)*logV)
space: O(V)
also V^2 = E but since E can be smaller than V sometimes so (V+E)
```
https://stackoverflow.com/questions/26547816/understanding-time-complexity-calculation-for-dijkstra-algorithm

## negative edges --> bellman ford
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
