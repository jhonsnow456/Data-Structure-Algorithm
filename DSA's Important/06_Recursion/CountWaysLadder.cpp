/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/

#include <bits/stdc++.h>

using namespace std;

int countWays(int n){
	if (n < 0) return 0;
	else if (n == 0) return 1;
	
	return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int32_t main(){
	// write the code here
	int n; cin >> n;

		cout << countWays(n) << endl;

	return 0;
}

