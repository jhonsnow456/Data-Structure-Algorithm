/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){
    
    int hashMap[26] = {};

    queue<char> q;
    vector<char> res;

    	for (char &c: S){
    		q.push(c); // push character into the queue
    		hashMap[c - 'a']++; // incrementing frequency

    		// check for non repeating character
    		while (!q.empty()){
    			if (hashMap[q.front() - 'a'] > 1) q.pop();
    			else {
    				cout << q.front();
    				res.push_back(q.front() - 'a');
    				break;
    			}
    		}

    		if (q.empty()) {
    			cout << 0;
    			res.push_back(0);
    		}
    	}

    return res;
}

int32_t main(){
	// write the code here
	string s; cin >> s;
	cout << s << endl;

	vector<char> res = FindFirstNonRepeatingCharacter(s);

		// for (int i = 0; i < res.size(); i++)
		// 	cout << res[i];

	return 0;
}
