/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>

using namespace std;

int cntSubarrays(vector<int> arr, int k){
	//complete this method
	unordered_map<int, int> prevSum;
	int res = 0, curSum = 0;

		for (int i = 0; i < arr.size(); i++){
			// add current element to 
			// sum so far
			curSum += arr[i];

			// if curSum == k just increase 
			// result 
			if (curSum == k) res++;

			// currsum exceeds given sum by currsum - sum. 
			// Find number of subarrays having this 
			// sum and exclude those subarrays
	        // from currsum by increasing count by
	        // same amount.
			if (prevSum.find(curSum - k) != prevSum.end())
				res += prevSum[curSum - k];

			// Add currsum value to count of
        	// different values of sum.
			prevSum[curSum]++;
		}

	return res;
}

int32_t main(){
	// write the code here
	vector<int> arr = {10, 2, -2, -20, 10};
	int k = 10; 

		cout << cntSubarrays(arr, k) << endl;

	return 0;
}
