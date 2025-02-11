## Logic 
- complexity without trie using arrays is O(n*m*m)
- with trie O(n*m)
- to optimise further ideas
  - way-1 (doesnt work) sort the string to find longest prefix string <br>
    - eg: a,aaa,ab,abbb -> if ans is abbbb then final ans is set to abbbb
    - eg: a,aaaa,ab,abbb -> if ans if aaaaa even then final ans is set to abbbb
  - way-2
  ``` // stop when a prefi is not present and dont take that path
    // instead of checking strings through arr, check them through the root
    // by using dfs```

## Beta Code
```cpp
#include <bits/stdc++.h>
class Node {
public:
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch) {
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    void put(char ch) {
        links[ch-'a']=new Node();
    }
    bool setEnd() {
        flag=true;
    }
    bool isEnd() {
        return flag;
    }

};

class Trie {
private: 
    Node* root;
public: 
    Trie() {
        root = new Node();
    }
    void insertString(string word) {
        Node* curr=  root;
        for (auto ch: word) {
            if (!curr->get(ch)) curr->put(ch);
            curr=curr->get(ch);
        }
        curr->setEnd();
    }

    bool isCompletePrefix(string word) {
        Node *curr = root;
        for (auto ch : word) {
            if (!curr->get(ch)->isEnd()) return false;
            curr= curr->get(ch); 
        } 
        return curr->isEnd();
    }
};

string compareString(string a, string b) {
    if ( (a.size() == b.size() && a<=b) ||(a.size() > b.size()) ) return a;
    return b;
}
string completeString(int n, vector<string> &a){
    // check all strings and update your ans

    // better solution
    // stop when a prefi is not present and dont take that path
    // instead of checking strings through arr, check them through the root
    // by using dfs
    Trie trie;
    string ans = "";
    for (int i=0; i<n; i++) {
        trie.insertString(a[i]);
    }
    for (int i=0; i<n; i++) {
        if (trie.isCompletePrefix(a[i])) ans = compareString(ans, a[i]); 
    }
    if (ans=="") return "None";
    return ans;
}
```
