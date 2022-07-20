/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

struct Node{
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void insertNode(Node* &head, int data){
	Node* newNode = new Node(data);

	if (head == NULL){
		head = newNode;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL) temp = temp->next;
	temp->next = newNode; 
}

Node *getNode(Node *head, int data){
	while (head->data != data) head = head->next;
	return head;
}
 

void deleteNode(Node *node){
	node->data = node->next->data;
	node->next = node->next->next;
	return;
}

void printNode(Node *head){
	while (head != NULL){
		cout << head->data << "->";
		head = head->next;
	}cout << "X" << endl;
}

void solve(){
	// write the code here
	Node *head = NULL;

		insertNode(head, 1);
		insertNode(head, 2);
		insertNode(head, 3);
		insertNode(head, 4);

	printNode(head);

	Node *node = getNode(head, 3);

		deleteNode(node);

	printNode(head);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    // std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			// std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}
