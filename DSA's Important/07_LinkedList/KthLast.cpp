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
 * Get the element at the Kth index from the last
 * of the LinkedList
*/
int kthLastElement(Node *head, int k){
    //Complete this function to return data middle node
    Node *slow = head;
    Node *fast = head;
    
    	for  (int i = 1; i <= k; i++)
    		fast = fast->next;

        while (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
    return slow->data;
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

		printLinkedList(head);

		cout << "Kth Element from the end of LinkedList: " << kthLastElement(head, 3) << endl;

	return 0;
}
