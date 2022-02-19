/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>

using namespace std;

void generateBrackets(string output, int N, int open, int close, int idx){
	if (idx == 2 * N){
		cout << output << ", ";
		return;
	}

	if (open < N)
		generateBrackets(output + '(', N, open + 1, close, idx + 1);

	if (close < open)
		generateBrackets(output + ')', N, open, close + 1, idx + 1);
}

int32_t main(){
	// write the code here
	string output;
	int N; cin >> N;

		generateBrackets(output, N, 0, 0, 0);

	return 0;
}
