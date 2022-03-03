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
 * To detect the cycle present in the Linkedlist
 * using unordred_map
*/
bool containsCycleUnorderedMap(Node *head){
    //Complete this function 
    unordered_map<Node *, bool> hashMap;
    Node *temp = head;

    	while (temp != NULL){
    		if (hashMap.count(temp) != 0) return true;
    		else hashMap[temp] = true;

    		temp = temp->next;
    	}

    return false;
}

/**
 * To detect the cycle present in the Linkedlist 
 * using floyd fast pointer algorithm
*/
bool containsCycle(Node *head){
    //Complete this function
    Node *rabbit = head;
    Node *tortoise = head;

    	while (tortoise and rabbit and rabbit -> next){
    		tortoise = tortoise->next;
    		rabbit = rabbit->next->next;

    		if (tortoise == rabbit)
    			return true;
    	}

    return false;
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

		cout << containsCycleUnorderedMap(head) << endl;
		cout << containsCycle(head) << endl;

	return 0;
}
