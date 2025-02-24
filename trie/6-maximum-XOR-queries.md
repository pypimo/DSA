https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

- sort the queries with on the basis of m in ascending order
- input the elements in trie according to order of m in each query
- find best answer in the current trie

```cpp
class Node {
public:
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit];
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit) {
        links[bit] = new Node();
    }
};

class Solution {
public:
Node* root= new Node();

    void insert(int num) {
        Node* curr = root;
        for (int i=31; i>=0; i--) {
            int bit = (num>>i)&1;
            if (!curr->containsKey(bit)) curr->put(bit);
            curr = curr->get(bit);
        }
    }

    int maxiXOR(int num) {
        Node* curr=root;
        int ans = 0;

        for (int i=31; i>=0; i--) {
            int bit = (num>>i)&1;

            if (curr->containsKey(!bit)) {
                curr = curr->get(!bit);
                ans = ans | (1<<i); 
            } else curr = curr->get(bit);
        }
        return ans;
    }

    vector<int> maximizeXor(vector<int> nums, vector<vector<int>> queries) {
        sort(nums.begin(), nums.end());
        
        int n= queries.size();
        vector<int> res(n,0);
        vector<vector<int>> sortedQueries;
        for (int i=0; i<n; i++) {
            sortedQueries.push_back({queries[i][1], queries[i][0], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        int cnt=0;
        for (auto q : sortedQueries) {
            int maxi = q[0], x=q[1], ind=q[2];
            while(cnt<nums.size() && nums[cnt]<=maxi) {
                insert(nums[cnt]);
                cnt++;
            }
            if (cnt==0) res[ind]=-1;
            else res[ind] = maxiXOR(x);
        }

        return res;
    }
};
```
