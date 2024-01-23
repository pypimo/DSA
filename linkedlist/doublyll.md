# array to doubly linked list
```cpp
class Node {
public:
	int data;
	Node* next;
	Node* back;

	Node(int data) {
		this->data = data;
		next = nullptr;
		back = nullptr;
	}

	Node(int data, Node* next, Node* back) {
		this->data = data;
		this->next = next;
		this->back = back;
	}
};

Node* convertarr2dll(vector<int> arr) {
	Node* head = new Node(arr[0]);
	Node* prev = head;
	for (int i=1; i<arr.size(); i++) {
		Node* temp = new Node(arr[i], nullptr, prev);
		prev->next = temp;
		prev = temp;
	}
	return head;
}

void print(Node* head) {
	while (head!=NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v{12,2,3,4};
	Node* head = convertarr2dll(v);
	print(head);

	return 0;
}
```

## 	
