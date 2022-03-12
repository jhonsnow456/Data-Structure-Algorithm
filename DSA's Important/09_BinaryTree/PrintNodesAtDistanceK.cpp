/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

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

void printAtLevelK(Node* root, int k){
		
		if(root==NULL) return;
		
		if(k == 0){
			cout<<root->data<<" ";
			return;
		}
	
		printAtLevelK(root->left,k-1);
		printAtLevelK(root->right,k-1);
		
	return;
}

int printNodesAtDistanceK(Node* root, Node* target,int k){

	if(root == NULL)
		return -1;

	if(root == target){
		printAtLevelK(target,k);
		return 0;
	}
	
	int DL = printNodesAtDistanceK(root->left,target,k);
	
		if(DL!=-1){
			if(DL + 1 == k)
				cout << root->data;

			else
				printAtLevelK(root->right,k-2-DL);
			
			return 1 + DL;
		}

	int DR = printNodesAtDistanceK(root->right,target,k);
	
		if(DR != -1){
			if(DR + 1 == k)
				cout<< root->data <<" ";
			
			else
				printAtLevelK(root->left,k-2-DR);
			
			return 1 + DR;
		}

	return -1;
}

int main(){
	
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
	
		Node* target = root->left->right;
		

	int k = 2;

		cout << "Node which are at distance K from the target Node: ";
		printNodesAtDistanceK(root,target,k); cout << endl;

	return 0;
}
