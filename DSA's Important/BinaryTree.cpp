/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/**
 * Build a tree
 * 
 * input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
*/
Node *buildTree(){
	int data; cin >> data;

		if (data == -1)
			return NULL;
		
		Node *node = new Node(data);
		node->left = buildTree();
		node->right = buildTree();

	return node;
}

/**
 * Level order traversal 
 * 
 * input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 * output:
 * 1, 
 * 2, 3, 
 * 4, 5, 6, 
 * 7, 
*/
void levelOrderPrint(Node *root){
	queue<Node *> q;

		q.push(root);
		q.push(NULL);


		while (!q.empty()){
			Node *temp = q.front();
			if (temp == NULL){
				cout << endl;
				q.pop();

				// insert a new null
				if (!q.empty())
					q.push(NULL);
			}else{
				q.pop();
				cout << temp->data << ", ";
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
		}
}

/**
 * Build tree Level Order
 * 
 * input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
 * output:
 * 1, 
 * 2, 3, 
 * 4, 5, 6, 
 * 7, 
*/
Node *buildTreeForLevelOrderInput(){
	int data; cin >> data;
	Node *root = new Node(data);
	queue<Node *> q;

		q.push(root);

		while (!q.empty()){
			Node *curr = q.front();
			q.pop();

			int child1, child2;
			cin >> child1 >> child2;

			if (child1 != -1){
				curr->left = new Node(child1);
				q.push(curr->left);
			}

			if (child2 != -1){
				curr->right = new Node(child2);
				q.push(curr->right);
			}
		}

	return root;
}

int height(Node *root){
	if (root == NULL)
		return 0;

	int heightLeftSubtree = height(root->left);
	int heightRightSubtree = height(root->right);

	return 1 + max(heightLeftSubtree, heightRightSubtree);
}

int diameter(Node *root){
	// base case;
	if (root == NULL)
		return 0;

		// diameter pass throught the root node
		int D1 = height(root->left) + height(root->right); 
		// showing faith on left subtree to have larger 
		// diameter or we can say shifting our root to left subtree
		int D2 = diameter(root->left); 
		// showing faith on right subtree to have larger 
		// diameter or we can say shifting our root to right subtree
		int D3 = diameter(root->right); 

	return max(D1, max(D2, D3));
}

int32_t main(){
	// write the code here
	Node *root = buildTreeForLevelOrderInput();

		levelOrderPrint(root);
		cout << "\nDiameter of the tree: " << diameter(root) << endl;

	return 0;
}
