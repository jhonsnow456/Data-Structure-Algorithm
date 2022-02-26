/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};


bool isPresent(Node * head, int key){
    //Complete this function 
    Node * temp = head;

    	while (temp != NULL){
    		if (temp->data == key)
    			return true;
    		temp = temp->next;
    	}

    return false;
}

int32_t main(){
	// write the code here
	Node *node = new Node(1);
	node->next = new Node(2);
	node->next->next = new Node(3);
	node->next->next->next = new Node(4);
	node->next->next->next->next = new Node(5);
	node->next->next->next->next->next = new Node(6);
	node->next->next->next->next->next->next = new Node(7);

		cout << isPresent(node, 4);

	return 0;
}

