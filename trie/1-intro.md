- helps perform three operations going char by char reference pointers
- insert, search, startsWith
## Using only arrays
```cpp
class Trie {
public:
    set<string> words,prefixes;
    // given: n words with m max length
    void insert(string word) {
        // O(log n ) + O(m*log n*m )
        words.insert(word);
        string inp="";
        for (auto ch: word) {
            inp+=ch;
            prefixes.insert(inp); 
        }
    }
    
    bool search(string word) {
        // O(log(n) )
        if (words.find(word)!=words.end()) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        // O(log(nm) )
        if (prefixes.find(prefix)!=prefixes.end()) return true;
        return false;
    }
};

// if n words are inserted
// insert -> n*(logn + mlognm)
```

## Beta Code
```cpp
class Node {
public:
    Node* links[26];
    bool flag=false;
};

class Trie {
private: 
    Node *root;
public:
    // Node*root = new Node();
    // way-1
    Trie() {
        root = new Node(); // way-2
    }
    void insert(string word) {
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->links[ch-97]) curr->links[ch-97] = new Node();
            curr = curr->links[ch-97];
        }
        curr->flag=true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->links[ch-97]) return false;
            curr = curr->links[ch-97];
        }
        if (curr->flag) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto ch: prefix) {
            if (!curr->links[ch-97]) return false;
            curr = curr->links[ch-97];
        }
    
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

## Recommended -> use functions
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
    void setEnd() {
        flag=true;
    }
    bool isEnd() {
        return flag;
    }
};  

class Trie {
private: 
    Node *root;
public:
    // Node*root = new Node();
    // way-1
    Trie() {
        root = new Node(); // way-2
    }
    void insert(string word) {
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->containsKey(ch)) curr->put(ch);
            curr = curr->get(ch);
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->containsKey(ch)) return false;
            curr = curr->get(ch);
        }
        return curr->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto ch: prefix) {
            if (!curr->containsKey(ch)) return false;
            curr = curr->get(ch);
        }
    
        return true;
    }
};
```
