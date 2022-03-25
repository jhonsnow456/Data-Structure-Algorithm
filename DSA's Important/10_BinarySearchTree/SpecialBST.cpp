/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

struct  Node{
	int key;
	Node *left;
	Node *right;
	Node *parent;

	Node(int key){
		this->key = key;
		left = right = parent = NULL;
	}
};

Node* findInOrderSuccessor(Node *inputNode){
    //Complete this Method, return the pointer to the inorder successor
    // HINT : Since the parent pointer is given, you can traverse upwards in the tree
    
    //find the left most child of right subtree if it exists
	if(inputNode->right){
	    Node* temp = inputNode->right;
	    
	    while(temp->left)
	    	temp = temp->left;
	    
	    return temp;
	 }

	else{
	    // traverse the parent till node is a right child of its parent
	    Node* parent = inputNode->parent;
	    Node* temp = inputNode;
	    
	    while(parent and parent->right == temp){
	      temp = parent;
	      parent = temp->parent;
	    }
	    
	    return parent;
	  }
}

/*
		5
	2 		6
1		4
	3
*/
int32_t main(){
	// write the code here
	Node *root = new Node(5);
	root->left = new Node(2);
	root->right = new Node(6);
	root->left->left = new Node(1);
	root->left->right = new Node(4);
	root->left->right->left = new Node(3);

		Node *target = root->left->right;

	root->left->parent = root;
	root->right->parent = root;
	root->left->left->parent = root->left;
	root->left->right->parent = root->left;
	root->left->right->left->parent = root->left->right;

		cout << findInOrderSuccessor(target)->key << endl;

	return 0;
}
