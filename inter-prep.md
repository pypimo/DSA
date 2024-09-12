# mocks
## 1
- sliding window
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/
- DSU dont use maps, prove how
https://leetcode.com/problems/satisfiability-of-equality-equations/description/

## 2
https://leetcode.com/problems/maximum-score-of-a-node-sequence/

# g
## inter1
graph ques, number of lock combinations if you can pick a number then pick any 4-dir adjacent, can pick a no. only once
- use dfs with new visited array for every node
- time is 4^(n*m) becuase 4 calls
- space is O(n*m) + O(n*m)
- for a 2D vis array to 1D --> (i,j) = i*c+j where C=no. of cols, this is always unique

- follow ups
- 8 directions
- if no constraint on adjacency

## inter 2
doubly ll, n searhes after u search something, if repeated we only ount the latest occurence  + n-1 uinque occ before of others
- O(n^2) to count unique  prev n, can attach priority and use priority queue, but still for recent n we need to check all
- best way O(n) is to use doubly ll, back and next pointers
- so if a query is reppeated, correct its prev positiion , chnge the back an next, and delete the prev
- so now we only have the most reent n searches
- time is O(n), space is O(n)
