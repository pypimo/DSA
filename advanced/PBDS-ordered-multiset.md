- Policy-Based Data Structures (PBDS)
- o4rder_of_key(x) returns count of elements strictly below x 

## using set
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Define an ordered_set using PBDS
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);

    int x = 25;

    // Find the number of elements strictly less than x
    int count = s.order_of_key(x);

    cout << "Number of elements below " << x << " is: " << count << '\n';

    return 0;
}

```

https://bit.ly/3PtLWLM

## CODE - using mutliset
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        
        // Your Code Here
        int n = arr.size(), ans=0, index=0;
        ordered_multiset st;
        for (int i=n-1; i>=0; i--) {
            int count = st.order_of_key({arr[i],0});
            ans += count;
            st.insert({arr[i],index++});
        }
        return ans;
    }
};
```
