/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/quick-sort/

#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &array, int start, int end){
	int pivot = array[end];
	int prev = start - 1;

		for (int next = start; next < end; next++){
			if (array[next] < pivot){
				prev++;
				swap(array[prev], array[next]);
			}
		}

		swap(array[prev + 1], array[end]);

	return prev + 1;
}

void quickSort(vector<int> &array, int start, int end){
	if (start >= end)
		return;

	int p = partition(array, start, end);

		quickSort(array, start, p - 1);
		quickSort(array, p + 1, end);
}

int32_t main(){
	// write the code here
	vector<int> array = {10, 5, 2, 0, 7, 6, 4};
	int n  = array.size() - 1;

		quickSort(array, 0, n);

		for (int i: array)
			cout << i << ", ";

	return 0;
}
