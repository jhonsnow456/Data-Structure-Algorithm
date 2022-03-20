/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	string N; cin >> N;
	int sum = 0;

		for (char &digit: N){
			sum += digit - '0';
			sum %= 9;
		}

		if (sum) sum = 9 - sum;

	int at = N.length();

		for (int i = sum == 0; i < N.length(); i++){
			if (N[i] - '0' > sum){
				at = i;
				break;
			}
		}

		string res = N.substr(0, at) + to_string(sum) + N.substr(at, N.length());
	
	cout << res << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}

