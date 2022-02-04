/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>

using namespace std;

string minWindow(string &s, string &t){
	int prev = 0, next = 0;
	string ans;
    unordered_map<char,int> mt, ms;
	    
	    for(char &c: t) mt[c]++;

    int mcnt = 0;
    int minimumWindowSize = INT_MAX;
    int windowSize;

	    while(next < s.length()){
	    	// expand the window by including current character
	    	char ch = s[next];
	    	ms[ch]++;

	    		// count the matched character till now
	    		if (mt[ch] != 0 and ms[ch] <= mt[ch])
	    			mcnt++;

	    		// another string
	    		// if all the charcter of the pattern are found 
	    		// in the current window then you can start contracting
	    		if (mcnt == t.length()){

	    			// start contracting from left
	    			while (mt[s[prev]] == 0 or ms[s[prev]] > mt[s[prev]]){
	    				ms[s[prev]]--;
	    				prev++;
	    			}

	    			// note the window size
	    			windowSize = next - prev + 1;
	    			if (windowSize < minimumWindowSize){
	    				minimumWindowSize = windowSize;
	    				ans = s.substr(prev, windowSize);
	    			}
	    		}

	    	next++;				    	
	    }

    return ans;
}

int32_t main(){
	// write the code here
	string s = "ABC", t = "B"; 
	string res = minWindow(s, t);
		cout << res << endl;
	return 0;
}
