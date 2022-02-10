/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/binary-search/1#

#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> v, int key){
	int start = 0;
	int end = v.size() - 1;

		while (start <= end){
			int mid = (start + end) / 2;

			if (v[mid] == key)
				return mid;
			else if (v[mid] < key)
				start = mid + 1;
			else
				end = mid - 1;
		}

	return -1;
}

int32_t main(){
	// write the code here
	vector<int> v = {1, 2, 10, 11, 19, 29, 28};
	int key = 2;

		cout << binary_search(v, key) << endl;

	return 0;
}

