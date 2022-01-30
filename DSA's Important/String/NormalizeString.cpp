/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

int skipWhiteSpace(const string &sentence, int idx){
		
		while (idx < sentence.length() and sentence[idx] == ' ')
			idx++;

	return idx; 
}

int normalizeWord(string &sentence, int idx){

	if (idx < sentence.length() and sentence[idx] != ' '){
		sentence[idx] = toupper(sentence[idx]);
		idx++;
	}

	while (idx < sentence.length() and sentence[idx] != ' '){
		sentence[idx] = tolower(sentence[idx]);
		idx++;
	} 

	return idx;
}

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    int idx = 0;

    	while (idx < copy.length()){
    		idx = skipWhiteSpace(copy, idx);
    		idx = normalizeWord(copy, idx);
    	}

    return copy;
}

int32_t main(){
	// write the code here
	string sentence;
	getline(cin, sentence);

		cout << normalize(sentence) << endl;

	return 0;
}
