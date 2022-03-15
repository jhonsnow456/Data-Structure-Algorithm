/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

void traverseTree(Node *root, int dist, map<int, vector<int>> &mp){
	if (root == NULL)
		return;

	mp[dist].push_back(root->data);
	traverseTree(root->left, dist - 1, mp);
	traverseTree(root->right, dist + 1, mp);
}

void verticalOrdertraversal(Node * root){
	map<int, vector<int>> mp;
	int dist = 0;

	traverseTree(root, dist, mp);

		for (auto i: mp){
			cout << i.first << ":";
			for (auto j: i.second)
				cout << j << ", ";
			cout << endl;
		}
}

int32_t main(){
	// write the code here
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(6);
	root->left->right->left = new Node(7);
	root->left->right->right = new Node(8);
	root->left->right->right->left = new Node(9);
	root->left->right->right->right = new Node(10);

		verticalOrdertraversal(root);

	return 0;
}
