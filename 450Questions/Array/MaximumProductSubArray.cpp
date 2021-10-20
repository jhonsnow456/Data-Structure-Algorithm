// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxProduct(vector<int> arr, int n){
	long long maxProduct, minProduct, result;
		maxProduct = minProduct = result = 1;
		
		for (int i = 0; i < n; i++){
			long long int x = arr[i];
			if (x < 0) swap(maxProduct, minProduct);
			
			maxProduct = max(x, x * maxProduct);
			minProduct = min(x, x * minProduct);

			result = max(result, maxProduct);
		}
    
    return result;
}

int main(){
	vector<int> arr = {6, -3, -10, 0, 2};
		cout << maxProduct(arr, arr.size())  << endl;
	return 0;
}
