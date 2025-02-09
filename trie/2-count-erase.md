- if you increment `count[ch]` of the present trie and then create refernce trie for char: hard to know when no string of that type exists
- instead attach counter to the reference trie of each char

## Code
```cpp
class Node {
public:
    Node* links[26];
    int countPrefix=0;
    int endsWith=0;

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
        endsWith++;
    }
    int isEnd() {
        return endsWith;
    }
    void increaseCount() {
        countPrefix++; 
    }
    void decreaseCount(int x) {
        countPrefix-=x;
        if (endswith>=x) endswith-=x;
    }
    int getCount() {
        return countPrefix; 
    }
    void setNull(char ch) {
        links[ch-'a'] = NULL;
    }

};  


class Trie{

    public:
    Node*root = new Node();

    void insert(string word) {
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->containsKey(ch)) curr->put(ch);
            
            curr = curr->get(ch);
            curr->increaseCount();
        }
        curr->setEnd();
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->containsKey(ch)) return 0;
            curr = curr->get(ch);
        }
        return curr->isEnd();
    }

    int countWordsStartingWith(string &word){
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->containsKey(ch)) return 0;
            curr = curr->get(ch);
        }
    
        return curr->getCount();
    }

    void erase(string &word){
        // if erase was meant for deleting all instances
        // int countWord = countWordsEqualTo(word);
        int countWord=1; // one erase deletes only one instance
        if (!countWord) return; // word does not exist
        
        Node* curr = root;
        for (auto ch: word) {
            // if you need to save memory and delete nodes, otherwise not needed
            if (curr->get(ch)->getCount()==countWord) {
                delete curr->get(ch);
                curr->setNull(ch);
                break;
            }

            curr=curr->get(ch);
            curr->decreaseCount(countWord);
        }
        
    }
};

```
### LOGIC
- for `insert`
    - when any word ends, the `endsWith` of reference node (of last character) is incremented
    - when any character is visited, the `countPrefix` of its referecen node is incremented

- for `countWordsEqualTo` we return the `endsWith` value of last char
- for `countWordsStartingWith` we return the `countPrefix` value of visited char
- for `erase` we delete one instance of every char in path, and decrement flag value when the word ends, if everything becomes zero delete the reference nodes for that char entirely
