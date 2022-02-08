/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(string x, string y){
	return x + y < y + x;
}

int32_t main(){
	// write the code here
	vector<string> arr = {"a", "ab", "aba"};
	int n = arr.size();

		sort(arr.begin(), arr.end(), comp);

		for (string s: arr) cout << s;

	return 0;
}
