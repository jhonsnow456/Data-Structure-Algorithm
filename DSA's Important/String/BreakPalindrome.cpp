/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/break-a-palindrome/

#include <bits/stdc++.h>

using namespace std;


string breakPalindrome(string palindrome) {
	int n = palindrome.length();

		// there is a single character
		if (n < 2) return "";

		for (int i = 0; i < n / 2; i++){
			if (palindrome[i] != 'a'){
				palindrome[i] = 'a';
				return palindrome;
			}
		} 

		// crossed the middle point of all a
		palindrome[n - 1] = 'b';

	return palindrome;
}

int32_t main(){
	// write the code here
	string palindrome; cin >> palindrome;

		cout << breakPalindrome(palindrome) << endl;

	return 0;
}
