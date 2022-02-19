/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/


/*
LOGIC
-----
										(A)BC
							/			  |				\
						A(B)C 	 		B(A)C 			C(B)A
						/   \			/	\			/	\
					AB(C)	ACB		BA(C)	BCA 	CB(A)	CAB
*/

#include <bits/stdc++.h>

using namespace std;

void permute(vector<string> &res, string &str, int l, int r){
	if (l == r){
		res.push_back(str);
		return;
	}

	else {
		for (int i = l; i <= r; i++){
			// permute
			swap(str[l], str[i]);
			
			// recusion is called
			permute(res, str, l + 1, r);

			// backtrack to get the original 
			// string before swap
			swap(str[l], str[i]);
		}
	}
}

int32_t main(){
	// write the code here
	string str = "ABC";
	vector<string> res;

		permute(res, str, 0, str.length() - 1);

		for (string s: res)
			cout << s << ", ";

	return 0;
}
