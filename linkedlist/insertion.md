## with VAL before POS
```cpp
Node * insert(Node * head, int n, int pos, int val) {
    // Write your code here
    Node* newNode = new Node(val);
    Node* temp = head;
    int ct=0;
    while(ct<pos-1) {
        temp = temp->next;
        ct++; 
    }
    if (pos == 0 || head==NULL) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
```

## at head

## at tail
