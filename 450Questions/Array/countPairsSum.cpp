// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

#include <iostream>
#include <unordered_map>

using namespace std;

int getPairCount(int arr[], int n, int k){
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;
	
	int count = 0;
	for (int i = 0; i < n; i++){
		mp[arr[i]]--;
		count += mp[k - arr[i]];
	}

	return count;
}

int main(){
	int arr[] = {1, 5, 7, 1};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << getPairCount(arr, n, 6) << endl;
	return 0;
}
