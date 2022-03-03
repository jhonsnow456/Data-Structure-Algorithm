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
Node *recursiveReverse(Node* &head){
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
 * reverse a linkedlist using iteration 
 * 
 * 
 * @param head passes as a reference object
 * @return the reference address of the head node 
 * 			after linkedlist is reverse
*/
void iterativeReverse(Node* &head){
	Node* prev = NULL;
	Node* curr = head;
	Node* nextCurr;

		while (curr != NULL){
			nextCurr = curr->next; //store the address of currentnode
			curr->next = prev; // update currentnode with address of prev node
			
			// update prev and curr node
			prev = curr;
			curr = nextCurr;
		}

	head = prev;
	return;
}

/**
 * reverse k individual block present in the 
 * liked list
 * 
 * @param head passes as a reference object
 * @param k length of the block
 * 
 * return the resultant linkedList
*/
Node *kReverse(Node *head, int k){
	// our base case
	// if the head reached to the end node

	if (head == NULL)
		return NULL;

	// reverse the first k nodes
	// through recusion
	Node *prev = NULL;
	Node *curr = head;
	Node *nextCurr;

	int cnt = 1;

		while (curr != NULL and cnt <= k){
			nextCurr = curr->next; //store the address of currentnode
			curr->next = prev; // update currentnode with address of prev node
			
			// update prev and curr node
			prev = curr;
			curr = nextCurr;
			cnt++;
		}

		if (nextCurr != NULL)
			head->next = kReverse(nextCurr, k);

	return prev;
}


/**
 * Merge the two pointer 
 * 
 * @param a pointer to the head node
 * @param b pointer to the node after mid
 * 
 * return the merged LinkedList 
*/
Node *merge(Node *a, Node *b){
	if (a == NULL)
		return b;

	if (b == NULL)
		return a;


	// recursive case
	Node *c;

		if (a->data < b->data){
			c = a;
			c->next = merge(a->next, b);
		}else{
			c = b;
			c->next = merge(a, b->next);
		}

	return c;
}

/**
 * Mid point of the LinkedList:
 * Implementation of the Floyd's slow and fast pointer 
 * algorithm 
 *  
 * return the mid point of the LinkedList
*/
Node *midPoint(Node *head){
	Node *slow = head;
	Node *fast = head->next;

		while (fast != NULL and fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next; // moves 2x slow pointer
		}

	return slow;
}

/**
 * Merge Sort algorithm performed
 * over the LinkedList
 * 
 * @parm head reference object of head node
*/
Node *mergeSort(Node* head){
	// base case:
	// if the node is a single node linked list
	// or an empty linkedlist 
	if (head == NULL or head->next == NULL)
		return head;

		// recursive case to find the mid-point of 
		// the array
		Node *mid = midPoint(head);

	// break the LinkedList from the middle
	Node *a = head;
	Node *b = mid->next;

		mid->next = NULL;

		// Recursive Sort
		a = mergeSort(a);
		b = mergeSort(b);

	return merge(a, b);	
}

/**
 * print the linked list
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
		printLinkedList(head); // 0->1->2->7->3->4->5->NULL

		iterativeReverse(head);
		printLinkedList(head); // 5->4->3->7->2->1->0->NULL

		head = recursiveReverse(head);
		printLinkedList(head); // 0->1->2->7->3->4->5->NULL

		head = kReverse(head, 3);
		printLinkedList(head); // 2->1->0->4->3->7->5->NULL

		head = mergeSort(head);
		printLinkedList(head); // 0->1->2->3->4->5->7->NULL

	return 0;
}
