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
		cout << temp->data << " ";
		temp = temp->next;
		cnt++;
	}
	return cnt;
}

Node* arr2ll(vector<int> arr) {
	Node *head = new Node(arr[0]);
	Node *mover = head;
	for (int i=1; i<arr.size(); i++) {
		Node *temp = new Node(arr[i]);
		mover->next = temp;
		mover=temp;
	}
	return head;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//array to linked list
	vector<int> arr = {29,33,41,15,8, 9, 0};
	Node* head = arr2ll(arr);
	int len = length(head);
	cout << "\n" << len; 
	

	return 0;
}
