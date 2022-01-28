/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	// write the code here
	string input;
	getline(cin, input);

		stringstream tokenstream(input);

	string token;
	vector<string> tokens;

		while (getline(tokenstream, token, ' '))
			tokens.push_back(token);

		for (string token: tokens)
			cout << token << ", ";

	return 0;
}
