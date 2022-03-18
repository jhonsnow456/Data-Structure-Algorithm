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

struct LinkedList{
	Node *head;
	Node *tail;
};

LinkedList treetoLinkedList(Node *root){
	LinkedList List;

		// if there is a single node or the node is NULL
		if (root == NULL or (root->left == NULL and root->right == NULL)){
			List.head = List.tail = root;
		}

		// if the right part of subtree is NULL
		else if (root->left != NULL and root->right == NULL){
			LinkedList leftLL = treetoLinkedList(root->left);
			leftLL.tail->right = root;

			List.head = leftLL.head;
			List.tail = root;
		}

		// if the left part of subtree is NULL
		else if (root->left == NULL and root->right != NULL){
			LinkedList rightLL = treetoLinkedList(root->right);
			root->right = rightLL.head;

			List.head = root;
			List.tail = rightLL.tail;
		}

		// if nither left nor right part of subtree is NULL
		else{
			LinkedList leftLL = treetoLinkedList(root->left);
			LinkedList rightLL = treetoLinkedList(root->right);

			leftLL.tail->right = root;
			root->right = rightLL.head;

			List.head = leftLL.head;
			List.tail = rightLL.tail;
		}
	
	return List;
}

int32_t main(){
	vector<int> arr{8, 3, 10, 1, 6, 14, 4, 7, 13};
	Node *root = NULL;

		for (int x: arr)
			root = insert(root, x);

	LinkedList List = treetoLinkedList(root);
	Node *temp = List.head;

		while (temp != NULL){
			cout << temp->key << "->";
			temp = temp->right;
		}cout << "|X|";

	return 0;
}
