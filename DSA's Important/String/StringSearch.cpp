/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result;
    int index = big.find(small);

	    while (index != -1){
	    	result.push_back(index);
	    	index = big.find(small, index+1);
	    }

    return result;
}

int32_t main(){
	// write the code here
	string bigString, smallString;
	getline(cin, bigString);
	cin >> smallString;

		auto res = stringSearch(bigString, smallString);
		
		for (auto i: res)
			cout << i << ", ";

	return 0;
}

