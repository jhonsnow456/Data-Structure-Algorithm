/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/counting-inversions/

#include <bits/stdc++.h>

using namespace std;

int crossInversion(vector<int> &array, int start, int end){
	vector<int> temp;

	int left = start;
	int mid = (start + end) / 2;
	int right = mid + 1;

	int cnt = 0;

		while (left <= mid and right <= end){
			if (array[left] < array[right])
				temp.push_back(array[left++]);
			else{
				cnt += mid - left + 1;
				temp.push_back(array[right++]);
			}
		}

		while (left <= mid)
			temp.push_back(array[left++]);

		while (right <= end)
			temp.push_back(array[right++]);

	for (int idx = start, k = 0; idx <= end; idx++, k++)
		array[idx] = temp[k];

	return cnt;
}

int inversionCount(vector<int> &array, int start, int end){
	if (start == end) return 0;

	int mid = (start + end) / 2;

		int c1 = inversionCount(array, start, mid);
		int c2 = inversionCount(array, mid + 1, end);
		int ci = crossInversion(array, start, end);

	return c1 + c2 + ci;
}

int32_t main(){
	// write the code here
	vector<int> array = {0, 5, 2, 3, 1};
	int start = 0, end = array.size() - 1;

		cout << inversionCount(array, start, end) << endl;

	return 0; 
}
