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

Node *inorderSuccessor(Node *root, Node *target){
	
	// if in the right subtree
	if (target->right != NULL){
		Node *temp = target->right;

			while (temp->left)
				temp = temp->left;

		return temp;
	}

	Node *temp = root;
	Node *succ = NULL;


		while (temp != NULL){
			if (temp->key > target->key){
				succ = temp;
				temp = temp->left;
			}

			else if (temp->key < target->key)
				temp = temp->right;

			else 
				break;
		}

	return succ;
}

int32_t main(){
	vector<int> arr{8, 3, 10, 1, 6, 14, 4, 7, 13};
	Node *root = NULL;

		for (int x: arr)
			root = insert(root, x);

	Node *target1 = root->left->right->right;
	Node *target2 = root->right;

		cout << "Inorder sucessor of 7: " << inorderSuccessor(root, target1)->key << endl;
		cout << "Inorder sucessor of 8: " << inorderSuccessor(root, target2)->key << endl;

	return 0;
}
