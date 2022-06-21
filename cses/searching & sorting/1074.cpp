/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

//https://cses.fi/problemset/task/1074/

// remember: to take median

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int
 
void solve(){
	// write the code here
	int N; cin >> N;
	vector<int> A(N);
 
	int sum = 0;
 
		for (auto &i: A)
			cin >> i;
 
	sort(A.begin(), A.end());
 
	int median = A[N/2], cost = 0;
 
		for (int i = 0; i < N; i++)
			cost += abs(median - A[i]);
 
	cout << cost << endl;
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
