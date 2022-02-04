/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1/#

#include <bits/stdc++.h>

using namespace std;

string smallestWindow(string str){
	string res;
	unordered_map<char, int> mstr, mptrn;

		for (char &c: str) mstr[c]++;

	int requiredCount = mstr.size();
	int currentCount = 0;

	int prev = 0, next = 0;
	int minWindowSize = INT_MAX;
	int windowSize = 0;

		while (next < str.length()){
			// count all the occurances of charcter in 
			// the string
			char ch = str[next];
			mptrn[ch]++;

			// If any distinct character matched 
			// then increment the count
			if (mptrn[ch] == 1)
				currentCount++;
			
			// if all the charcter is matched 
				if (currentCount == requiredCount){
					// Try to minimize the window
					while (mptrn[str[prev]] > 1){
						if (mptrn[str[prev]] > 1) 
							mptrn[str[prev]]--;
						prev++;
					}

					// update the window size
					windowSize = next - prev + 1;
					if (windowSize < minWindowSize){
						minWindowSize = windowSize;
						res = str.substr(prev, windowSize);
					}
				}

			next++;
		}

	return res;
}

int32_t main(){
	// write the code here
	string str; cin >> str;
		cout << smallestWindow(str) << endl;
	return 0;
}
