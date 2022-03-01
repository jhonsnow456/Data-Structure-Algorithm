/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};
 
/**
 * Insert node at the head of the Linked List
 * 
 * 
 * @param head passed as reference object
 * @param data data to be inserted 
*/
void insertAtHead(Node* &head, int data){
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}

/**
 * Insert node anywhere in the linkedlist but at specified position
 * 
 * 
 * @param head passes as reference object
 * @param data data to be inserted
 * @param pos anywhere in the middle of the linkedlist 
*/
void inserAtGivenPos(Node* &head, int data, int pos){
	if (pos == 0)
		insertAtHead(head, data);
	else{
		Node *temp = head;

		while (pos--)
			temp = temp->next;

		Node *middleNode = new Node(data);
		middleNode->next = temp->next;
		temp->next = middleNode;
	}
}

/**
 * reverse a linkedlist using recursion
 * 
 * 
 * @param head passes as a reference object
 * @return the reference address of the head node 
 * 			after linkedlist is reverse
*/
Node *recursiveReverse(Node *head){
	// if reached the end of the node
	// or only one node is left
	if (head == NULL or head->next == NULL)
		return head;

	else{
		Node *sHead = recursiveReverse(head->next);
		
		Node *recLastHead = head->next;
		recLastHead->next = head;
		head->next = NULL;

		return sHead;
	} 
}

/**
 * print the linked list
 * 
 * 
 * @param head is read-only obhject
*/
void printLinkedList(const Node* head){
	while (head){
		cout << head->data << "->";
		head = head->next;
	}cout << "NULL" << endl;
}

int32_t main(){
	// write the code here
	Node *head = NULL;
	
		insertAtHead(head, 5);
		insertAtHead(head, 4);
		insertAtHead(head, 3);
		insertAtHead(head, 2);
		insertAtHead(head, 1);
		insertAtHead(head, 0);

		inserAtGivenPos(head, 7, 2);
		
		printLinkedList(head);

		head = recursiveReverse(head);

		printLinkedList(head);

	return 0;
}
