/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;

	Node(int key){
		this->key = key;
		this->left = this->right = NULL;
	}
};

Node* insert(Node *root, int key){
	if (!root)
		return new Node(key);

	if (key < root->key)
		root->left = insert(root->left, key);

	else 
		root->right = insert(root->right, key);

	return root;
}

bool isBSTUtil(Node *root, int min, int max){
	/* an empty tree is BST */
	if (root == NULL)
		return true;

	/* A tree is said to be a balanced BST only if
	the minimum value than the root node is at left and 
	the maximum value than the root node is at right*/
	if (root->key < min or root->key > max)
		return false;

	return 
		isBSTUtil(root->left, min, root->key) and 
		isBSTUtil(root->right, root->key, max);	
}

bool isBST(Node *root){
	// complete this method
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

int32_t main(){
	// write the code here
	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->right = new Node(6);

		cout << "Is BST: " << isBST(root);

	return 0;
}
