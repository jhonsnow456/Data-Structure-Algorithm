// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestConsecutiveSubsequence(int arr[], int n){	
	sort(arr, arr + n);
	int count = 1, ans = 1;
	
	for (int i = 0; i < n - 1; i++){
		if (arr[i + 1] == arr[i] + 1){
			count++;
			ans = max(ans, count);
		}else if(arr[i] == arr[i + 1]){
			continue;
		}else{
			count = 1;
		}
	} 

	return ans;
}
  
int main(){
	int arr[] = {1, 9, 3, 10, 4, 20, 2};
	int size = sizeof(arr) / sizeof(arr[0]);
		cout << longestConsecutiveSubsequence(arr, size)  << endl;
	return 0;
}
