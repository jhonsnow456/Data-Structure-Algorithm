// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool subArrayExists(int arr[], int n){
	set<int> s;
	int sum = 0;
	
	for (int i = 0; i < n; i++){
		sum += arr[i];
		if (sum == 0) return true;
		if (s.find(sum) != s.end()) return true;
		else s.insert(sum);
	}

	return false;
}

int main(){
	int arr[] = {4, 2, -3, 1, 6};
	int size = sizeof(arr) / sizeof(arr[0]);

		cout << ((subArrayExists) ? "Exists" : "Do not Exists") << endl; 

	return 0;
}
