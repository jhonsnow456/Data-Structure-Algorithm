// https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

#include <iostream>
#include <unordered_map>

using namespace std;

void elementoccuringmorethanNdivK(int arr[], int n, int k){
	int x = n / k;
	unordered_map<int, int> mp;
		
		for (int i = 0; i < n; i++)
			mp[arr[i]]++;
		
		for (auto i: mp)
			if (i.second > x)
				cout << i.first << " ";
	cout << endl;
}

int main(){
	int arr[] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 4;

		elementoccuringmorethanNdivK(arr, size, k);

	return 0;
}
