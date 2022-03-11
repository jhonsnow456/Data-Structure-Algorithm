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

// ==============================================================
// 							Build A Binary Tree
// ==============================================================

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

// ==============================================================
// 							Level Order Traversal
// ==============================================================

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


// ===========================================================
// 					Diameter of Binary Tree
// ===========================================================


// Normal approch
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

// Optimized Approch
struct HDPair{
	int height;
	int diameter;
};

HDPair optimalDiameterofBinaryTree(Node *root){
	if (root == NULL)
		return {0, 0};

		// otherwise
		HDPair Left = optimalDiameterofBinaryTree(root->left);
		HDPair Right = optimalDiameterofBinaryTree(root->right);

	HDPair p;

		p.height = max(Left.height, Right.height) + 1;
		
		int D1 = Left.height + Right.height;
		int D2 = Left.diameter;
		int D3 = Right.diameter;

		p.diameter = max(D1, max(D2, D3));

	return p;
}

// =========================================================
// 						Decendent Sum
// =========================================================
int decendentSum(Node *root){
	if (root == NULL)
		return 0;
	if (root->left == NULL and root->right == NULL)
		return root->data;

	int leftSum = decendentSum(root->left);
	int rightSum = decendentSum(root->right);
	
	int data = root->data;
	root->data = leftSum + rightSum;

	return root->data + data;
} 

// =================================================================
// 							Height Balanced Tree
// =================================================================
pair<int, bool> isHeightBalanced(Node *root){
	if (root == NULL)
		return {0, true};

	// left subtree & right subtree
	pair<int, bool> Left = isHeightBalanced(root->left);
	pair<int, bool> Right = isHeightBalanced(root->right);

	pair<int, bool> res;

		res.first = 1 + max(Left.first, Right.first);

		if (abs(Left.first - Right.first) <= 1 and Left.second and Right.second)
			res.second = true;

	return res;
}

int32_t main(){
	// write the code here
	Node *root = buildTreeForLevelOrderInput();

		cout << "Level Order Binary Tree: \n";
		levelOrderPrint(root);

		cout << "\nDiameter of the tree: " << diameter(root) << endl;
		cout << "\nOptimized Diameter of the binary tree: " << optimalDiameterofBinaryTree(root).diameter << endl;
		cout << "\nDescent Sum: " << decendentSum(root) << endl;
		
		cout << "\nLevel Order Binary Tree: \n";
		levelOrderPrint(root);

		cout << "\nIs the tree Balanced? " << (isHeightBalanced(root).second ? "Yes it's!\n": "No it's not\n");

	return 0;
}
