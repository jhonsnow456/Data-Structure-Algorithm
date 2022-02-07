/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/quickselect-algorithm/

#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &array, int left, int right){
	int pivot = array[right], prev = left - 1;

		for (int next = left; next < right; next++){
			if (array[next] < pivot){
				prev++;
				swap(array[prev], array[next]);
			}
		}

		swap(array[prev], array[right]);

	return prev + 1;
}

int kthsmallest(vector<int> &array, int left, int right, int k){

	int index = partition(array, left, right);

		if (index - left == k)
			return array[index];

		if (index - left > k)
			return kthsmallest(array, left, index - 1, k);

		else
			return kthsmallest(array, index + 1, right, k);
}

int32_t main(){
	// write the code here
	vector<int> array = {10, 5, 2, 0, 7, 6, 4};
	int n  = array.size() - 1;
	int k = 4;
	int ksm = kthsmallest(array, 0, n, k);

		if (ksm != INT_MAX)
			cout << "The Kth element :" << ksm;
		else
			cout << "Hence, value not found!!" << endl;

	return 0;
}
