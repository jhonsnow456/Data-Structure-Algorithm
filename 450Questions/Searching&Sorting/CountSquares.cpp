/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/count-squares3649/1

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int countSquares(int N){
	int cnt = 0;

		for (int i = 1; i * i < N; i++){
			cnt++;
		}

	return cnt;
}

void solve(){
	// write the code here
	int n; cin >> n;
	cout << countSquares(n) << endl;
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
