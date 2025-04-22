# lower_bound()
http://codeforces.com/blog/entry/142156

`lower_bound(a.begin(), a.end(), val);`
only runs in O(logn) time on random-access iterators, such as those in a vector. In particular, this will run in O(n)
 time on sets and maps. For sets and maps, you have to use the lower_bound specifically for that data structure.
 ```set<int> a;
int val;
// whatever
lower_bound(a.begin(), a.end(), val);```
