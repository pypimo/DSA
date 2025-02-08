- if you increment `count[ch]` of the present trie and then create refernce trie for char: hard to know when no string of that type exists
- instead attach counter to the reference trie of each char

```cpp
class Node {
public:
    Node* links[26];
    int count=0;
    int flag=0;

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
        flag++;
    }
    bool isEnd() {
        return flag;
    }
    void increaseCount() {
        ++count; 
    }
    void decreaseCount(int x) {
        count-=x;
    }
    int getCount() {
        return count; 
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
            curr->increaseCount();
        }
        curr->setEnd();
    }
    
    bool countSearch(string word) {
        Node* curr = root;
        for (auto ch: word) {
            if (!curr->containsKey(ch)) return false;
            curr = curr->get(ch);
        }
        return curr->isEnd();
    }
    
    int countStartsWith(string prefix) {
        Node* curr = root;
        for (auto ch: prefix) {
            if (!curr->containsKey(ch)) return false;
            curr = curr->get(ch);
        }
    
        return curr->getCount();
    }

    void deleteWord(string word) {
        int countWord = countSearch(word);
        Node* curr = root;
        // subtract from each
        for (auto ch: prefix) {
            if (!curr->containsKey(ch)) return false;
            if (curr->get(ch)->getCount()==countWord) curr=new Node();
            else {
                curr=curr->get(ch);.
                curr->decreaseCount(countWord);

            }
        }
    
        return curr->getCount();
    }
    
};
```
