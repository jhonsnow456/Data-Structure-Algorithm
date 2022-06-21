/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

//https://cses.fi/problemset/task/1070/

// idea : to print all the even number in one go 
// then print the odd number edge cases will be number 1, 2, and 3

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	int n; cin >> n;

	if (n == 1) cout << 1 << endl;

	else if (n < 4) cout << "NO SOLUTION" << endl;

	else {
		for (int i = 2; i <= n; i += 2)
			cout << i << " ";
		for (int i = 1; i <= n; i += 2)
			cout << i << " ";
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

