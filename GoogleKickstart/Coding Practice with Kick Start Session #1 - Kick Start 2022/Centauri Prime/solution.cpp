/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

bool isVolwel(char c){
	c = tolower(c);
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

string centauriPrime(string kingdomName){
	int lastCharacter = kingdomName.length() - 1;

		if (isVolwel(kingdomName[lastCharacter]))
			return kingdomName + " is ruled by Alice.";
		else{
			if (kingdomName[lastCharacter] == 'y' or kingdomName[lastCharacter] == 'Y')
				return kingdomName + " is ruled by nobody.";
			else
				return kingdomName + " is ruled by Bob.";	
		}
}

void solve(){
	// write the code here
	string kingdomName; cin >> kingdomName;
	cout << centauriPrime(kingdomName) << endl;
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

