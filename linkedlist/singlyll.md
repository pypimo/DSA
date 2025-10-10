```cpp
class Node {
	public:
	int data;
	Node* next;

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};
```

#length
```cpp
int length(Node* head) {
	int cnt=0;
	Node* temp=head;
	while (temp) {
		//cout << temp->data << " ";
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
```

# array to linked list
```cpp
void func() {
	vector<int> arr = {2,3,4,5};
	Node *head = new Node(arr[0]);
	Node *mover = head;
    cout << mover->data << " ";
	for (int i=1; i<arr.size(); i++) {
		Node *temp = new Node(arr[i]);
		mover->next = temp;
		mover=temp;
		cout << mover->data << " ";
	}
}
```

## delete head
```cpp
Node* temp = head;
head = head->next;
delete temp;
```
## delete tail
```cpp
while (temp->next->next!=NULL) {
  temp = temp->next;
}
temp->next=nullptr;
```

## deletion
```cpp
Node* deleteNode(Node* head, int pos)
{
	if (head==NULL) return head;
	Node* temp = head;
	if (pos==0) {
		head=head->next;
		return head;
	}
	int ct=0;
	Node* prev=NULL;
	while (temp!=NULL) {
		if (ct==pos) {
			prev->next=prev->next->next;
		} 
		// dont use 'else' here bcz then it will enter infinite while
			prev=temp;
			temp=temp->next;
			ct++;
	}
	return head;
}
```

## insertion
```cpp
Node* insert(Node* head, int n, int pos, int val) {
    Node* newNode = new Node(val);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL) {
        if (cnt==pos-1) {
            newNode->next = temp->next;
            temp->next = newNode;
        } 
        temp = temp->next;
        cnt++;
    }
    return head;
}
```
## insertion head
```cpp
Node* newNode = Node(int val);
newNode->next = head;
head = newNode;
return head;
```
## insertion tail
```cpp
while (temp->next!=NULL) {
	temp = temp->next;
}
temp->next = newNode;
return head;
```
## reverse linked list
```cpp
if (head==NULL) return head;
Node* temp=head;
Node* prev = NULL;
while(temp!=head){
	Node* xtra = temp->next;
 	temp->next= prev;
	prev = temp;
 	temp=xtra;
}
head = prev;
return head;
```
## length
```cpp
int length(Node* head) {
	int cnt=0;
	Node* temp=head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
```

## Floyd’s Cycle-Finding Algorithm
https://www.youtube.com/watch?v=PvrxZaH_eZ4
- imagine this like spinning planets, the faster a planet completes its revolution, the more often it can be spotted from the slower planet
