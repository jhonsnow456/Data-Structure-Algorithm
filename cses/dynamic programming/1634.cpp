/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://cses.fi/problemset/task/1634
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int
 
void solve(){
	// write the code here
	int n, x; 
	cin >> n >> x;
 
		vector<int> c(n);
 
		for (int i = 0; i < n; i++)
			cin >> c[i];
 
	vector<int> dp(x + 1, INT32_MAX);
	dp[0] = 0;
 
		for (int i = 1; i <= x; i++){
			for (int j = 0; j < n; j++){
				if (i - c[j] >= 0){
					dp[i] = min(dp[i], dp[i - c[j]] + 1);
				}
			}
		}
 
	if (dp[x] == INT32_MAX) cout << -1 << endl;
	else cout << dp[x];
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
