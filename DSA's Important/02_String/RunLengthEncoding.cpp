/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/string-compression/

#include <bits/stdc++.h>

using namespace std;

string compressString(const string &str){   
    //complete the function to return output string
    int count = 1;
    string  output = "";

    	for (int i = 1; i < str.length(); i++){
    		if (str[i - 1] == str[i])
    			count++;
    		else {
    			output += str[i - 1] + to_string(count);
    			count = 1;
    		}
    	}

    	output += str[str.length() - 1] + to_string(count); 

    return output.length() > str.length() ? str : output;
}

int32_t main(){
	// write the code here
	string str; cin >> str;

		cout << compressString(str) << endl;

	return 0;
}
