# lower_bound()
http://codeforces.com/blog/entry/142156

`lower_bound(a.begin(), a.end(), val);`
only runs in O(logn) time on random-access iterators, such as those in a vector. In particular, this will run in O(n)
 time on sets and maps. For sets and maps, you have to use the lower_bound specifically for that data structure.

```
set<int> a;
int val;
lower_bound(a.begin(), a.end(), val);
```
INSTEAD USE THIS:
```
set<int> a;
int val;
// whatever
a.lower_bound(val);
```

# vector<int> as a key in an unordered_map.
wrong
- unordered_map requires the key type to have a hash function.
- vector<int> does not have a built-in hash function in C++, so using it as a key in unordered_map causes a compilation error

INSTEAD USE
- custom hash or
- pair<int,int>
