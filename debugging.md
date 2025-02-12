## Trie - completeStringPrefix
The issue in your code is due to an incorrect use of a non-static data member in a default argument. Specifically, this line:

```
string dfsCompleteString(Node* curr=root, string ans="") {...}
```
The error occurs because root is a non-static member of the class Trie, and C++ does not allow non-static data members to be used as default arguments for member functions.

## bit manipulation
why ((num<<i) & 1) works but not  ((1<<i) & num)
REASON
(num<<i & 1) = 1 means ith bit is set wherease
((1<<i) & num) > 0 means ith bit is set
