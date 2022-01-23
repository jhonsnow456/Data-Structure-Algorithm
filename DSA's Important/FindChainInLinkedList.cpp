/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

/*
* Write a program to check wether the linkedlist contain a cycle or 
* not ?
*/
#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;

	Node (int data){
		this->data = data;
		this->next = NULL;
	}
};

void push_back(Node* &head, int data){
	Node* node = new Node(data);

		if (head == NULL){
			head = node;
			return;
		}else{
			Node* temp = head;
			while (temp->next != NULL)
				temp = temp->next;

			temp->next = node;
		}
}

void display(Node* const head){
	Node* temp = head;

		while (temp != NULL){
			cout << temp->data << ",";
			temp = temp->next;
		}
}

bool containCycle(Node* const head){
	unordered_map<Node*, bool> hash_table;
	Node *temp = head;

		while (temp != NULL){
			if (hash_table.count(temp) != 0) return true;
			hash_table[temp] = true;
			temp = temp->next;
		}

	return false;
}

int32_t main(){
	// write the code here
	Node *temp = NULL;

		push_back(temp, 1);
		push_back(temp, 2);
		push_back(temp, 3);
		push_back(temp, 4);
		push_back(temp, 5);

		display(temp);
		cout << endl;

	Node* node = temp->next->next->next->next;
	node->next = temp->next->next; 

		cout << ((containCycle(node) ? "Cycle Exists!!" : "Cycle don't Exists!!")) << endl;
	
	return 0;
}
