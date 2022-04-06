/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	string s; cin >> s;
	int n = s.length();

	int len = 1, ans = 1;

		for (int i = 1; i < n; i++){
			if (s[i - 1] == s[i])
				len++;
			else{
				ans = max(ans, len);
				len = 1; // reset the  len to 1
			}
	 	}

	ans = max(ans, len);

	cout << ans;
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

