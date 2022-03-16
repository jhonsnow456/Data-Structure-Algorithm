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

	Node (int key){
		this->key = key;
		this->left = NULL;
		this->right = NULL;
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

void printInOrder(Node *root){
	if (!root)
		return;

	printInOrder(root->left);
	cout << root->key << " ";
	printInOrder(root->right);
}

int32_t main(){
	vector<int> arr{8, 3, 10, 1, 6, 14, 4, 7, 13};
	Node *root = NULL;

		for (int x: arr)
			root = insert(root, x);

		printInOrder(root);

	return 0;
}
