/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>

using namespace std;

string uniqueSubstring(string &str){
	int start = 0, end = 0;

	int startWindow = -1;
	unordered_map<char, int> mp;

	int windowLength = 0;
	int maxWindowLength = 0;

		while (end < str.length()){
			char ch = str[end];
			// if it is inside the hashmap & its index >= start of the window
			if (mp.find(ch) != mp.end() and mp[ch] >= start){
				start = mp[ch] + 1;
				windowLength = end - start;
			}

			// update the last occurence
			mp[ch] = end;
			windowLength++;
			end++;

			// upadte the maxWindowLength at every step
			if (windowLength > maxWindowLength){
				startWindow = start;
				maxWindowLength = windowLength;
			}
		}

	return str.substr(startWindow, startWindow + maxWindowLength);
}

int uniqueSubstringLength(string &str){
	unordered_map<char, int> mp;
	int res = 0;

	int n = str.length();
	int prev = 0, next = 0;

		while (next < n){
			if (mp.find(str[next]) != mp.end())
				prev = max(prev, mp[str[next]] + 1);
			
			mp[str[next]] = next;
			res = max(res, (next - prev) + 1);
			next++;
		}

	return res;
}

int32_t main(){
	// write the code here
	string str; cin >> str;
		cout << uniqueSubstring(str) << endl;
		cout << uniqueSubstringLength(str) << endl;
	return 0;
}
