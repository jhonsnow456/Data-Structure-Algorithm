/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

struct Node{
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node *mergeLinkedList(Node *linklist1, Node *linklist2){
	// when list1 is empty then our output will 
	// be same as list2
	if (linklist1 == NULL) return linklist2;
	
	// when list1 is empty then our output will 
	// be same as list1
	if (linklist2 == NULL) return linklist1;

	// pointing l1 and l2 to smallest and greatest one
	if (linklist1->data > linklist2->data) swap(linklist1, linklist1);

	Node *res = linklist1;

		while (linklist1 != NULL and linklist2 != NULL){
			Node *temp = NULL;

			while (linklist1 != NULL and linklist1->data <= linklist2->data){
				temp = linklist1; // storing last sorted node
				linklist1 = linklist1->next;
			}

			// link previous sorted node with 
			// next larger node in list2
			temp->next = linklist2;
			swap(linklist1, linklist2);
		}

	return res;
}

void displayLinkedList(Node* head){
	while (head != NULL){
		cout << head->data << " -> ";
		head = head->next;
	}cout << "X" << endl;
}

void solve(){
	// write the code here
	Node *linklist1 = new Node(1);

		linklist1->next = new Node(2);
		linklist1->next->next = new Node(5);
		linklist1->next->next->next = new Node(8);
		linklist1->next->next->next->next = new Node(10);

	Node *linklist2 = new Node(3);

		linklist2->next = new Node(7);
		linklist2->next->next = new Node(10);
		
		cout << "Link List 1: "; displayLinkedList(linklist1);
		cout << "Link List 2: "; displayLinkedList(linklist2);

	Node *res = mergeLinkedList(linklist1, linklist2);

		displayLinkedList(res);

}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    // std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			// std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}
