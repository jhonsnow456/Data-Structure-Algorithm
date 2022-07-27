/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void merge(vector<int> &A, vector<int> &B){
	int n = A.size(), m = B.size();
	
	for (int i = 0; i < n; i++){
		if (A[i] > B[0]) swap(A[i], B[0]);

		int temp = B[0], j;

		for (j = 1; j < m and B[j] < temp; j++)
			B[j - 1] = B[j];	
		B[j - 1] = temp;
	}
}

void print(vector<int> &res){
	for (int &i: res)
		cout << i << " ";
	cout << endl;
}

void solve(){
	// write the code here
	int n, m; cin >> n >> m;
	vector<int> A(n), B(m);

		for (int &i: A) cin >> i;
		for (int &i: B) cin >> i;

	merge(A, B);

	print(A);
	print(B);
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
