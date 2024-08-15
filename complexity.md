two -pointer
  dbt: if for ever movement secon pointer follows me then complexity us 1+2+3+.... = n(n+1)/2
  WRONG!!
  because the second popinter maintains possiotio and first pointer only increments by 1
  so total steps is 1+2+5+2+... = n steps total as that is the size
O(n)

## mergesort
TC O(nlogn)
SC O(n)  ONLY
recursion stackspace is not O(n) but O(logn) since depth first ie first all merge sorts like n, n/2, n/4 take place only then right half is considered
