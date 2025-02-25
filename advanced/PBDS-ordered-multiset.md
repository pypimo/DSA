https://bit.ly/3PtLWLM

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
