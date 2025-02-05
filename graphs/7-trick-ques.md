some questions are in the form of grids and you have to imagine each grid cell as a node to solve
- if you need to do a dfs to club 1s for eg
- way1: start dfs at any 1, inside each dfs have 4 dfs calls for 4 directoins -> time compleity 4^ (n*m) using recursive tree
- way2: visit each grid call and look at 4 directions and club (eg: using kruskal's) time complextity = n*m
