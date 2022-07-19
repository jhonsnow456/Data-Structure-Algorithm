/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/reverse-linked-list/

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

Node *revLinkedList(Node *head){

	Node *currNode = NULL;

		while (head != NULL){
			// step 4: create the next node
			Node *nextNode = head->next;
			
			// step1: create the link to the curr node
			head->next = currNode;

			// step 2: Jump the curr node to present head node
			currNode = head;

			// step 3: Now what? u have broken the link to reverse
			//		   so you have to store the address of the 
			// 		   the next node
			head = nextNode;
		}

	return currNode;
}

void displayLinkedList(Node* head){
	while (head != NULL){
		cout << head->data << " -> ";
		head = head->next;
	}cout << "X" << endl;
}

void solve(){
	// write the code here
	Node *head = new Node(1);

		head->next = new Node(2);
		head->next->next = new Node(3);
		head->next->next->next = new Node(4);

	displayLinkedList(head);

		head = revLinkedList(head);

	displayLinkedList(head);
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
