- if you increment `count[ch]` of the present trie and then create refernce trie for char: hard to know when no string of that type exists
- instead attach counter to the reference trie of each char

## Beta Code
```cpp
#include <bits/stdc++.h> 
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
    int isEnd() {
        return flag;
    }
    void increaseCount() {
        count++; 
    }
    void decreaseCount(int x) {
        count-=x;
        if (flag>=x) flag-=x;
    }
    int getCount() {
        return count; 
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
            if (curr->get(ch)->getCount()==countWord) {
                //cout << ch << " hello\n";
                delete curr->get(ch);
                curr->setNull(ch);
                break;
            } else {
                curr=curr->get(ch);
                curr->decreaseCount(countWord);
            }
        }
        
    }
};

```
