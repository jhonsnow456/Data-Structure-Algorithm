/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

struct  Node{
	int data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* lca(Node* root, int a, int b){
	//Complete this function and return address of the node 
	if (root == NULL) return root;   
	if (root->data == a or root->data == b) return root;

	Node *leftans = lca(root->left, a, b);
	Node *rightans = lca(root->right, a, b);

	if (leftans != NULL and rightans != NULL) return root;
	
	if (leftans != NULL) return leftans;
	else return rightans;
}

int32_t main(){
	// write the code here
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	root->right->right->left = new Node(6);
	root->right->right->right = new Node(7);

	int val1 = 4, val2 = 7;
	cin >> val1 >> val2;

		cout << lca(root, val1, val2)->data << endl;

	return 0;
}
