## two -pointer
  - dbt: if for ever movement secon pointer follows me then complexity us 1+2+3+.... = n(n+1)/2
  - WRONG!!
  - because the second popinter maintains possiotio and first pointer only increments by 1
  - so total steps is 1+2+5+2+... = n steps total as that is the size O(n)

## mergesort
TC O(nlogn)
SC O(n)  ONLY
recursion stackspace is not O(n) but O(logn) since depth first ie first all merge sorts like n, n/2, n/4 take place only then right half is considered

## dfs inside dfs calls
- exponenetial!!!!!!!!!!
- eg if dfs call at one node, calls dfs of others, and visited aray is pass by value, ie you NEED to visit unique path
- so time complexity is 2 raise to n = pow(2,n) = 2^n
- for normaldfs

## complexity of ds
linked lists: insertion and lookup time is O(n)
arrays: insertion O(n) and lookup time is O(log n)
search trees: insertion and look up time is O(log n) -> tree always needs to be balanced
hash table : insertion and look up time is O(1) -> in case of max collissions worst case is O(n)

## complexity of recursive functions
- make the recursion tree eg n call
- calc time for each call eg O(1)
- Final complexity  = complexity of each call * no. of calls
(Reference[https://www.youtube.com/watch?v=Uv1LpSKZcm4])
