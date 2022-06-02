/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	int n; cin >> n;
	string s; cin >> s;
	bool isUpper = false, isLower = false, isSpecialCharacter = false, isDigit = false;

		// traverse the string to see the codition
		for (auto i: s){
			if (isupper(i)) isUpper = true;
			if (islower(i)) isLower = true;
			if (i - '0' >= 0 and i - '0' <= 9) isDigit = true;
			if (i == '#' or i == '@' or i == '*' or i == '&') isSpecialCharacter = true;
		}

	int reqlen = n - 7;

		if (reqlen >= 0){
			if (!isUpper) s.push_back('A');
			if (!isLower) s.push_back('a');
			if (!isDigit) s.push_back('0');
			if (!isSpecialCharacter) s.push_back('@');
		}else{
			if (!isUpper) {s.push_back('A'); reqlen++;}
			if (!isLower) {s.push_back('a'); reqlen++;}
			if (!isDigit) {s.push_back('0'); reqlen++;}
			if (!isSpecialCharacter) {s.push_back('@'); reqlen++;}

			while (reqlen < 0){
				s.push_back('a');
				reqlen++;
			}
		}

	cout << s << endl;
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
