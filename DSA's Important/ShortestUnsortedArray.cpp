/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <bits/stdc++.h>

using namespace std;

bool outOfOrder(vector<int> arr, int i){
	int x = arr[i];
	if(i == 0)
		return x > arr[1];
	if(i == arr.size()-1)
		return x < arr[i - 1];

	return x > arr[i + 1] or x < arr[i - 1];
}


// return the length of subarry to be corrected
int findUnsortedSubarray(vector<int>& arr) {
	int n = arr.size();
	int smallest = INT32_MAX, largest = INT32_MIN;

		for (int i = 0; i < n; i++){
			int x = arr[i];

			if (outOfOrder(arr, i)){
				smallest = min(smallest, x);
				largest = max(largest, x);
			}
		}

		if (smallest == INT32_MAX) return 0;

	int left = 0;

		while (arr[left] <= smallest)
			left++;

	int right = n - 1;

		while (largest <= arr[right])
			right--;
	 
	return right - left + 1;
}

// return the range of the subarray left and right index
pair<int, int> findUnsortedSubarray(vector<int> &arr){
	int n = arr.size();
	int smallest = INT32_MAX, largest = INT32_MIN;

		for (int i = 0; i < n; i++){
			int x = arr[i];

			if (outOfOrder(arr, i)){
				smallest = min(smallest, x);
				largest = max(largest, x);
			}
		}

		if (smallest == INT32_MAX) return {-1, -1};

	int left = 0;

		while (arr[left] <= smallest)
			left++;

	int right = n - 1;

		while (largest <= arr[right])
			right--;
	 
	return {left, right};
}

int32_t main(){
	// write the code here
	vector<int> v = {2, 1, 4, 3};
	
	// pair<int, int> res = findUnsortedSubarray(v);
	// 	cout << res.first << ": " << res.second << endl;

	int dis = findUnsortedSubarray(v);
		cout << dis << endl;
	
	return 0;
}
