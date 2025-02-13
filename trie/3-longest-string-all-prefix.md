
https://www.naukri.com/code360/problems/complete-string_2687860

## Logic 
- complexity without trie using arrays is O(n*n*m)
- way-1 trie O(n*m) -> check if for each character the refernce node's `flag = true`
- to optimise further ideas
  - IDEA (doesnt work) sort the string to find longest prefix string <br>
    - eg: a,aaa,ab,abbb -> if ans is abbbb then final ans is set to abbbb
    - eg: a,aaaa,ab,abbb -> if ans if aaaaa even then final ans is set to abbbb
  -  IDEA way-2
    - when a prefix is not present and dont take that path (so no need to visit any other string on that path)
    - instead of checking strings through arr, check them through the root
    - by using dfs

```cpp
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
```

## Code - way1
```cpp
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

## way 2 - using dfs
```cpp
class Trie {
private: 
    Node* root;
public: 
    Trie() {
        root = new Node();
    }
    void insertString(string word) {
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->get(ch)) curr->put(ch);
            curr=curr->get(ch); 
        }
        curr->setEnd();
    }

    string dfsCompleteString(Node* curr, string ans="") {
        if (!curr) curr=root;
        string str = ans;
        for (char ch='a'; ch<='z'; ch++) {
            if (!curr->get(ch) || !curr->get(ch)->isEnd()) continue;
            ans = compareString(  dfsCompleteString( curr->get(ch),str+ch ), ans  );
        } 
        return ans;
    }

    
    string compareString(string a, string b) {
        if ( (a.size() == b.size() && a<=b) ||(a.size() > b.size()) ) return a;
        return b;
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for (int i=0; i<n; i++) {
        trie.insertString(a[i]);
    }

    string ans = trie.dfsCompleteString(NULL);
    if (ans=="") return "None";
    return ans;
}
```
## Debugging
The issue in your code is due to an incorrect use of a non-static data member in a default argument. Specifically, this line:

```cpp
string dfsCompleteString(Node* curr=root, string ans="") {
```
The error occurs because root is a non-static member of the class Trie, and C++ does not allow non-static data members to be used as default arguments for member functions.
