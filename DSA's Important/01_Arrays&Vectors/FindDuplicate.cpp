/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int duplicate_val(vector<int> const &A){
	int slow  = A[0];
	int fast = A[0];

	do{
		slow = A[slow];
		fast = A[A[fast]];
	}while (fast != slow);

	fast = A[0];

	while (fast != slow){
		slow = A[slow];
		fast = A[fast];
	}

	return slow;
}

void solve(){
	// write the code here
	int n; cin >> n;
	vector<int> A(n);

		for (int &i: A) cin >> i;

	cout << duplicate_val(A) << endl;
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
