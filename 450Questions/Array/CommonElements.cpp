// https://practice.geeksforgeeks.org/problems/common-elements1132/1 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3){
	vector<int> result;
	set<int> set1, set2, set3;
		
		// insert unique and common element in set1
		for (int i = 0; i < n1; i++)
			set1.insert(A[i]);
		
		// insert unique and common element in set2
		for (int i = 0; i < n2; i++)
			if (set1.find(B[i]) != set1.end())
				set2.insert(B[i]);

		// insert unique and common element in set3 
		for (int i = 0; i < n3; i++)
			if (set2.find(C[i]) != set2.end())
				set3.insert(C[i]);

		for (auto i: set3)
			result.push_back(i);

	return result;
}

int main(){
	int n1 = 6; int A[] = {1, 5, 10, 20, 40, 80};
	int n2 = 5; int B[] = {6, 7, 20, 80, 100};
	int n3 = 8; int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
	
	vector<int> v = commonElements(A, B, C, n1, n2, n3);

	for (auto i: v)
		cout  <<  i << " ";
	cout << endl;

	return 0;
}
