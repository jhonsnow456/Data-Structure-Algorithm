/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;


// Method 1: Using String stream
void stringStream(string &input){
	stringstream tokenstream(input);

	string token;
	vector<string> tokens;

		while (getline(tokenstream, token, ' '))
			tokens.push_back(token);

		for (string token: tokens)
			cout << token << ", ";
}

// Method 2: Using strtok
void stringToken(char* input){
	char* token = strtok(input, " ");

	while (token != NULL){
		cout << token << ", ";
		token = strtok(NULL, " ");
	}
}


// Method 3: Using my string own tokenzation function
char* strtoken(char* str, char delimiter){
	static char *input = NULL;

		if (str != NULL) input = str;
		if (input == NULL) return NULL;

	char *token = new char[strlen(input) + 1];
	int i = 0;

		for (; input[i] != '\0'; i++)
			if (input[i] != delimiter) 
				token[i] = input[i];
			else{
				token[i] = '\0';
				input = input + i + 1;
				return token;
			}

		token[i] = '\0';
		input = NULL;

	return token;
}

void stringTokenenization(char* input){
	char* token = strtoken(input, ' ');

	while (token != NULL){
		cout << token << ", ";
		token = strtoken(NULL, ' ');
	}
}

int32_t main(){
	// write the code here
	string input;
	getline(cin, input);

		stringStream(input);

		cout << endl;
		
	char input1[input.length() + 1];

		strcpy(input1, input.c_str());
		stringToken(input1);

		cout << endl;


	char input2[input.length() + 1];

		strcpy(input2, input.c_str());
		stringTokenenization(input2);

	return 0;
}
