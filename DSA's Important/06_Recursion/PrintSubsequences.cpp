/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/print-subsequences-string/

#include <bits/stdc++.h>

using namespace std;

void printSubsequence(set<string> &res, string input, string output){
	if (input.empty()){
		res.insert(output);
		return;
	}

	printSubsequence(res, input.substr(1), output + input[0]); // include first character in substring
	printSubsequence(res, input.substr(1), output); // exclude first charcter in substring
}

int32_t main(){
	// write the code here
	set<string> res;
	string input = "abc", output = "";

		printSubsequence(res, input, output);

		for (auto s: res)
			cout << s << ", ";

	return 0;
}
