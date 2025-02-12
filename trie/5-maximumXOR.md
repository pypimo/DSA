https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
Logic:
- insert all nums in trie
- for a given number x, find the highest xor giving number
- eg x=1000111
- so y=0111000 is best number possible
- start traversing trie from left, check if the best possible route exists (1/0), if not go to the next available root
- guaranteeed to find best answer0000
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
                ans+=pow(2,i);
            } else curr = curr->get(bit);
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        int ans=0;

        for (int num: nums) insert(num);
        for (auto num: nums) ans = max(maxiXOR(num), ans);

        return ans;
    }
};
```
## time complexity
- length of number = M = 31 (constant)
- N = total nums in array
- for every number-  we try to find the best possible number -> takes O(M)
- total  = O(N*M) = O(N)
