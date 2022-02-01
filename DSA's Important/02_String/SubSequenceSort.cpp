/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

/*
  INPUT
  ------
    abc
  
  OUTPUT
  ------
    ,a ,b ,c ,ab ,ac ,bc ,abc ,
*/

#include <bits/stdc++.h>

using namespace std;

void subsequence(string s, string o, vector<string> &v){
	if (s.size() == 0) {
		v.push_back(o);
		return;
	}

	// considering the first character
	char firstCharcter = s[0];
	string reducedString = s.substr(1);

	// including the first character 
	subsequence(reducedString, o + firstCharcter, v);

	// excluding the first charcter
	subsequence(reducedString, o, v);
}

bool comp(string a, string b){
	return (a.length() == b.length()) ? a < b : a.length() < b.length(); 
}

int32_t main(){
	// write the code here
	string str, output = ""; cin >> str;
	vector<string> res;

		subsequence(str,  output, res);
		sort(res.begin(), res.end(), comp);

		for (string i: res) cout << i << " ,";

	return 0;
}
 
