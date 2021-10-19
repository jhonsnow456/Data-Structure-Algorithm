// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rearrange(int arr[], int n){
	sort(arr, arr + n);
	int i = 1, j = 1;
	
	while (j < n){
		if (arr[j] > 0) break;
		j++;
	}

	while (arr[i] < 0 and j < n){
		swap(arr[i], arr[j]);
		i += 2;
		j += 1;
	}
}

int main(){
	int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	int size = sizeof(arr) / sizeof(arr[0]);

	rearrange(arr, size);

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
