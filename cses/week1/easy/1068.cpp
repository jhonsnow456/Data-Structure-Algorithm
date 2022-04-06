/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	int n; cin >> n;
		
		if (n == 1) cout << 1;
		else{
			do{
				cout << n << " ";
				if (n % 2 == 0) n /= 2;
				else n = (n * 3) + 1; 
			}while (n != 1);  

			cout << n;
		}
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

