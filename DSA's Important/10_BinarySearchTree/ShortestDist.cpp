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

Node* LCA(Node* root, int a, int b){
	//Complete this function and return address of the node 
	if (root == NULL or root->data == a or root->data == b) return root;

	Node *leftans = LCA(root->left, a, b);
	Node *rightans = LCA(root->right, a, b);

	if (leftans != NULL and rightans != NULL) return root;
	
	if (leftans != NULL) return leftans;
	else return rightans;
}

int search(Node *root, int k, int currDist){
	if (root == NULL)
		return -1;

	if (root->data == k)
		return currDist;

	int left = search(root->left, k, currDist + 1);

		if (left != -1)
			return left;

	int right = search(root->right, k, currDist + 1);
	
	return right;
}

int shortestDist(Node *root, int a, int b){
	Node *lca = LCA(root, a, b);

	int d1 = search(lca, a, 0);
	int d2 = search(lca, b, 0);

	return d1 + d2;
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
	// cin >> val1 >> val2;


		cout << shortestDist(root, val1, val2) << endl;

	return 0;
}
