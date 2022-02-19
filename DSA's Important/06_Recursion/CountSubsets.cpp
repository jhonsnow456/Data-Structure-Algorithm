/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x-using-recursion/

#include <bits/stdc++.h>

using namespace std;

int countSubsets(vector<int> &arr, int N, int idx, int X){
	if (idx == N){
		if (X == 0) return 1;
		else return 0;
	}

	int include = countSubsets(arr, N, idx + 1, X - arr[idx]);
	int exclude = countSubsets(arr, N, idx + 1, X);

	return include + exclude;
}

int32_t main(){
	// write the code here
	vector<int> arr{1, 2, 3, 4, 5, 6};
	int X = 6;

		cout << countSubsets(arr, arr.size(), 0, X) << endl;

	return 0;
}
 
