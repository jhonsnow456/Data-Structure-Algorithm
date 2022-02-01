/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/longest-mountain-in-array/

#include <bits/stdc++.h>

using namespace std;

int longestMountain(vector<int>& arr) {
	int n = arr.size();
	int height = 0;

		if (n < 3) return 0;
		else{
			for (int i = 1; i < n - 1;){
				// check if arr[i] is a peak
				if (arr[i - 1] < arr[i] and arr[i] > arr[i + 1]){
					int cnt = 1;
					int j = i;

					// backward slope
					while (j >= 1 and arr[j - 1] < arr[j]){
						j--;
						cnt++;
					}

					// cnt forward slope
					while (i < n - 1 and arr[i] > arr[i + 1]){
						i++;
						cnt++;
					}

					height = max(height, cnt);
				}else {
					i++;
				}
			}	
		}

	return height;		
}

int32_t main(){
	// write the code here
	vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
		cout << longestMountain(arr) << endl;
	return 0;
}
