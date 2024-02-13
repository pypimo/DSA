
# multimap
- multiple elements can have the same keys
- m[key] = value doesnt work
- use instead m.insert({key,value});
- default ascedning order sort
- sort in desc -> multimap<int,char, greater<int>>

# count()
```cpp
map<int,int> m;
m.count(k); // returns the no. of times key k is present
```
- can be used when one wants to check if a key is present and m[k] might be 0
- so if (m.count(k) && m[k]!=val...) ....

# ordered vs unordered maps

# look-up time in map
