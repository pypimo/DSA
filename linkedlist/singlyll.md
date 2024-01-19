# array to linked list
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//array to linked list
	vector<int> arr = {2,3,4,5};
	Node *head = new Node(arr[0]);
	Node *mover = head;
	for (int i=1; i<arr.size(); i++) {
		Node *temp = new Node(arr[i]);
		mover->next = temp;
		mover=temp;
		cout << mover->data << " ";
	}

	cout << length(head);
	

	return 0;
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
## insertoin head
```
Node* newNode = Node(int val);
newNode->next = head;
head = newNode;
return head;
```
## insetion tail
```
while (temp->next!=NULL) {
	temp = temp->next;
}
temp->next = newNode;
```
return head;
