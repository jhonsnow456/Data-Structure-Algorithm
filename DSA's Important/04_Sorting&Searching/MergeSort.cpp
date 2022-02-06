/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

// merge logic
void merge(vector<int> &array, int start, int end){
	vector<int> temp;

	int left = start;
	int mid = (start + end) / 2;
	int right = mid + 1;

		while (left <= mid and right <= end){
			if (array[left] < array[right])
				temp.push_back(array[left++]);
			else
				temp.push_back(array[right++]);
		}

		while (left <= mid)
			temp.push_back(array[left++]);

		while (right <= end)
			temp.push_back(array[right++]);

	for (int idx = start, k = 0; idx <= end; idx++, k++)
		array[idx] = temp[k];
}

// sorting logic
void mergeSort(vector<int> &array, int start, int end){
	if (start == end) return;

	int mid = (start + end) / 2;

	// merge left
	mergeSort(array, start, mid);
	// merge right
	mergeSort(array, mid + 1, end);

	merge(array, start, end);
}

int32_t main(){
	// write the code here
	vector<int> array = {10, 5, 2, 5, 7, 6, 4};
	int start = 0, end = array.size() - 1;

		mergeSort(array, start, end);

		for (auto x: array)
			cout << x << ", ";

	return 0; 
}
