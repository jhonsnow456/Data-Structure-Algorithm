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

Node* sortedArrayToBST(vector<int> arr, int start, int end){
	if (start > end)
		return NULL;

	int mid = (start + end) / 2;

	Node *root = new Node(arr[mid]);

	root->left = sortedArrayToBST(arr, start, mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);
	return root;
}

void print(Node *root){
	if (root == NULL)
		return;

	cout << root->key << " ";
	print(root->left);
	print(root->right);
}

int32_t main(){
	vector<int> arr{8, 3, 10, 1, 6, 14, 4, 7, 13};
	Node *root = NULL;

		sort(arr.begin(), arr.end());

		Node *res = sortedArrayToBST(arr, 0, arr.size() - 1);
		print(res);

	return 0;
}
