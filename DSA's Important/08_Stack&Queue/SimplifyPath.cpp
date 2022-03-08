/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/simplify-path/

#include <bits/stdc++.h>

using namespace std;

vector<string> tokenizeArrayOnRegex(string path){
	vector<string> elements;
	string rgx_str = "/+";

	   	regex rgx(rgx_str);

	   	sregex_token_iterator iter(path.begin(), path.end(), rgx, -1);
	    sregex_token_iterator end;

	    while (iter != end){
	    	elements.push_back(*iter);
	    	++iter;
	    }

	return elements;
}

vector<string> tokenizeArrayOnSStream(string path){
	istringstream iss(path);
	vector<string> tokens;
	string token;

		while (getline(iss, token, '/')){
			if (token == "." or token == "")
				continue;
			tokens.push_back(token);
		}

	return tokens;
}

string simplifyPath(string path){
    //complete this code return the simplified path
   	string res;
   	vector<string> tokens = tokenizeArrayOnSStream(path);
   	vector<string> stk;

   		for (auto token: tokens){
   			if (!stk.empty() and token == "..")
   				stk.pop_back();
   			if (!(token == "." or token == ".." or token == ""))
   				stk.push_back(token);
   		}

   		for (auto word: stk)
   			res += "/" + word;

    return res.length() ? res : "/";
}

int32_t main(){
	// write the code here
	string path; cin >> path;
	cout << simplifyPath(path) << endl;
	return 0;
}
