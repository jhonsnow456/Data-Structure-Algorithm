/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;

int rotatedSearch(vector<int> arr, int key){
	int start = 0;
	int end = arr.size() - 1;

		while (start <= end){
			int mid = (start + end) / 2;

			if (arr[mid] == key)
				return mid;

			if (arr[start] <= arr[mid]){
				// logic left half
				if (arr[start] <= key and key <= arr[mid])
					end = mid - 1;
				else
					start = mid + 1;
			}else {
				// logic right half
				if (arr[mid] <= key and key<= arr[end])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}

	return -1;
}

int32_t main(){
	// write the code here
	vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
	int key = 5; cin >> key;

		cout << rotatedSearch(arr, key) << endl;

	return 0;
}
