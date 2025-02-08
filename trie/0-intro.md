- helps perform three operations going char by char reference pointers
- insert, search, startsWith

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
