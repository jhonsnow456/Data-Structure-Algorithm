/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://cses.fi/problemset/task/1637/

// idea : think greedly

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int maxDigit(int n){
	int mx = 0;

		while (n != 0){
			mx = max(n % 10, mx);
			n /= 10;
		}

	return mx;
};

void solve(){
	// write the code here
	int n; cin >> n;
	int cnt = 0;

		while (n != 0){
			n -= maxDigit(n);
			cnt++;
		}

	cout << cnt << endl;
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

