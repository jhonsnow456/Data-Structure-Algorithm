/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric

Sample Output
-------------
82 12
77 13
92 022
*/

#include <bits/stdc++.h>

using namespace std;


string extractStringAtKeys(string str, int keys){
	// string tokenizer
	char *s = strtok((char*)str.c_str(), " ");

		while (keys > 1){
			s = strtok(NULL, " "); // extract the next token
			keys--;
		}

	return (string)s;
}

bool lexicoCompare(pair<string,string> s1, pair<string,string> s2){
	string key1, key2;
		
		key1 = s1.second;
		key2 = s2.second;
	
	return key1 < key2;
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
	string key1, key2;
		
		key1 = s1.second;
		key2 = s2.second;

	return stoi(key1) < stoi(key2);
}

int32_t main(){
	// write the code here
	int n; cin >> n;
	
	// consume the first "\n" after
	// integral input
		cin.get(); 

	string line;
	vector<string> lines;

		for (int i = 0; i < n; i++){
			getline(cin, line);
			lines.push_back(line);
		}

	int key; 
	string reversal, ordering;

		cin >> key >> reversal >> ordering;

	// To extract keys for comparison & store them 
	vector<pair<string, string>> lineKeyPair;

		for (int i = 0; i < n; i++)
			lineKeyPair.push_back({lines[i], extractStringAtKeys(lines[i], key)});

	// To Sort the string based on Value as input
	enum sortBasedOn{numeric, lexicographical};
	map<string, sortBasedOn> mp;

		switch (mp[ordering]){
			case numeric:
				sort(lineKeyPair.begin(), lineKeyPair.end(), numericCompare);
				break;

			case lexicographical:
				sort(lineKeyPair.begin(), lineKeyPair.end(), lexicoCompare);
				break;
		}

		if (reversal == "true")
			reverse(lineKeyPair.begin(), lineKeyPair.end());

		for(auto i: lineKeyPair)
			cout << i.first << endl; 
		
	return 0;
}
