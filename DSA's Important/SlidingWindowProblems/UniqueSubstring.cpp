/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>

using namespace std;

int uniqueSubstring(string &str){
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
	return 0;
}
