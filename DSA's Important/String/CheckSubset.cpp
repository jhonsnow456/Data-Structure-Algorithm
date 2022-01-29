/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/


/*
	INPUT
	-----
	codingminutes
	cinxs	

	OUTPUT
	------
	False
*/

#include <bits/stdc++.h>

using namespace std;

bool checkSubset(string &a, string &b){
	int i = a.length() - 1;
	int j = b.length() - 1;

		while (j >= 0 and i >= 0){
			if (a[i] == b[j]){
				i--; j--;
			}
			else i--;			
		}

	return j == -1;
}

int32_t main(){
	// write the code here
	string a, b;
	cin >> a >> b;

		cout << ((checkSubset(a, b))? "True": "False") << endl;

	return 0;
}
