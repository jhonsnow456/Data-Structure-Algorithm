/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void swapSiblings(Node *root){
	if (root == NULL)
		return;

	swapSiblings(root->left);
	swapSiblings(root->right);
	swap(root->left, root->right);
}

void print(Node *root){
	if (root == NULL)
		return;

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

bool equal(Node * root1, Node * root2){
    //Complete the Function
	if (root1 == root2)
		return true;

	return (root1 and root2) and (root1->data == root2->data) and
		(equal(root1->left, root2->left) and equal(root1->right, root2->right)) or 
		(equal(root1->right, root2->left) and equal(root1->left, root2->right));
}

int32_t main(){
	// write the code here
	Node* root1 = new Node(1);
	root1->left = new Node(2);
	root1->right = new Node(3);
	root1->left->left = new Node(4);
	root1->left->right = new Node(5);
	root1->right->right = new Node(6);
	root1->left->right->left = new Node(7);
	root1->left->right->right = new Node(8);
	root1->left->right->right->left = new Node(9);
	root1->left->right->right->right = new Node(10);

	Node *root2 = new Node(1);
	root2->right = new Node(2);
	root2->left = new Node(3);
	root2->right->right = new Node(4);
	root2->right->left = new Node(5);
	root2->left->left = new Node(6);
	root2->right->left->right = new Node(7);
	root2->right->left->left = new Node(8);
	root2->right->left->left->right = new Node(10);
	root2->right->left->left->left = new Node(9);

		swapSiblings(root1);
		print(root1); cout << endl;
		print(root2);

		cout << equal(root1, root2) << endl;

	return 0;
}
