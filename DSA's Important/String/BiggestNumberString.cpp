/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(string &a, string &b){
	return a + b > b + a;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
	vector<string> strNumbers;

		for (int &number: numbers)
			strNumbers.push_back(to_string(number));

		sort(strNumbers.begin(), strNumbers.end(), comp);

	string res = "";

		for (string strNumber: strNumbers)
			res += strNumber;

	return res;
}

int32_t main(){
	// write the code here
	vector<int> numbers = {10, 11, 20, 30, 3};

		cout << concatenate(numbers);

	return 0;
}
