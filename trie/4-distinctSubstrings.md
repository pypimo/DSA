https://www.naukri.com/code360/problems/count-distinct-substrings_985292
- length of word = n
- using maps
- Time Complexity = O(n*n)
- Space Complexity = O(n*n*n/2) -> bcz n^2 substring, each with average legnth of n/2 (since min length = 0, max length =n)

- Using Tries - space complexity can be optimised
- Time Complexity = O(n*n)
- Space Complexity = O(n*n) -> worst case: all substrings are distinct eg: abcdefg
  
```cpp
class Node {
public:
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch) {
        return (links[ch-'a']);
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    void put(char ch) {
        links[ch-'a'] = new Node();
    }
};  

class Trie {
private: 
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    int countInsert(string str) {
        int count=1; // empty substring
        int n=str.size();
        for (int i=0; i<n; i++) {
            Node* curr = root;
            for (int j=i; j<n; j++) {
                if (!curr->containsKey(str[j])) {
                    count++;
                    curr->put(str[j]);
                } 
                curr = curr->get(str[j]);
            }
        }
        return count;
    }
};
int countDistinctSubstrings(string &s)
{
    Trie trie;
    return trie.countInsert(s);
}
```
