/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
	int sum = INT32_MIN, maxtillnow = 0;

	// 	arr = -1 2 3 4 -2 6  -8 3
		for (int i = 0; i < n; i++){
			maxtillnow += arr[i];
			sum = max(sum, maxtillnow); 
			// sum = -1 2 5 9 13 
			maxtillnow = (maxtillnow < 0) ? 0 : maxtillnow;
			// maxtillnow = 0 2 5 9  7 13  5 8 
		}

	return (sum < 0) ? 0: sum;   
}

int32_t main(){
	// write the code here
	vector<int> arr = {-1, 2, 3, 4, -2, 6, -8, 3};
		cout << maxSubarraySum(arr) << endl;
	return 0;
}
