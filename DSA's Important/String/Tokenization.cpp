/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

void stringStream(string &input){
	stringstream tokenstream(input);

	string token;
	vector<string> tokens;

		while (getline(tokenstream, token, ' '))
			tokens.push_back(token);

		for (string token: tokens)
			cout << token << ", ";
}

void stringToken(char* input){
	char* token = strtok(input, " ");

	while (token != NULL){
		cout << token << ", ";
		token = strtok(NULL, " ");
	}
}

int32_t main(){
	// write the code here
	string input;
	getline(cin, input);

		stringStream(input);

		cout << endl;
		
	char input1[1000];
	// cin.getline(input1, 1000);
	int itr = 0;

		for (char c: input)
			input1[itr++] = c;

		stringToken(input1);

	return 0;
}
