/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>

using namespace std;

vector<string> keypad{"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadCode(string input, string output, int idx = 0){
	if (input[idx] == '\0'){
		cout << output << ", ";
		return;
	}

	int currentDigit = input[idx] - '0';

	// check for exceptional case of 0 and 1;
	if (currentDigit == 0 or currentDigit == 1)
		printKeypadCode(input, output, idx + 1);

	// print the combination
	for (char keyChar: keypad[currentDigit])
		printKeypadCode(input, output + keyChar, idx + 1);
}

int32_t main(){
	// write the code here
	string input, output;
	cin >> input;

		printKeypadCode(input, output);

	return 0;
}
