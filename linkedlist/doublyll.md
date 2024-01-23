# array to doubly linked list
```cpp
class Node {
public:
	int data;
	Node* next;
	Node* back;

	Node(int data1) {
		this->data = data1;
		next = nullptr;
		back = nullptr;
	}

	Node(int data1, Node* next1, Node* back1) {
		this->data = data1;
		this->next = next1;
		this->back = back1;
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
