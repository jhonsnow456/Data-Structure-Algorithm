/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/

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

void traverseTree(Node *root, vector<int> &res){
	if (!root)
		return;

	queue<Node *> q;
	q.push(root);

	while (!q.empty()){
		int n = q.size();

		for (int i=1; i <=n; i++){
			Node* temp = q.front();
			q.pop();


			if (i == 1)
				res.push_back(temp->data);

			if (temp -> left != NULL)
				q.push(temp->left);

			if (temp -> right != NULL)
				q.push(temp->right);
		}		
	}

}

vector<int> leftView(Node * root){
    //Complete the function   
    vector<int> res;

    	traverseTree(root, res);

    return res;
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

		vector<int> res = leftView(root);

		for (auto i: res)
			cout << i << " ";

	return 0;
}
