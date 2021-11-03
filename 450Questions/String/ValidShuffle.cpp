// https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkLength(string s1, string s2, string result){
	if (s1.length() + s2.length() != result.length()) return false;
	else return true;
}

bool validshuffle(string s1, string s2, string result){
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	sort(result.begin(), result.end());

	int i = 0, j = 0, k = 0;
	
	while (k != result.length()){
		if (i < s1.length() and s1[i] == result[k]) i++;
		else if (j < s2.length() and s2[j] == result[k]) j++;
		else break;
		k++;
	} 

	if (i < s1.length() or j < s2.length()) return false;
	return true;
}	

int main(){
	string s1 = "XY", s2 = "12";
	vector<string> results = {"1XY2", "Y1X2", "Y21XX"};

		for (string s: results)
			if (checkLength(s1, s2, s) == true and validshuffle(s1, s2, s) == true)
				cout << "Valid Shuffle" << endl;
			else 
				cout << "Invalid Shuffle" << endl;

	return 0;
}
