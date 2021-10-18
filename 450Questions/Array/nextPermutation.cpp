// https://leetcode.com/problems/next-permutation/
// https://practice.geeksforgeeks.org/problems/next-permutation5226/1


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int> &nums, int i, int j){
	swap(nums[i], nums[j]);
}

void reverse(vector<int> &nums, int start){
	int i = start, j = nums.size() - 1;
	while (i < j){
		swap(nums, i, j);
		i++, j--;
	}
}

void nextPermutation(vector<int> &nums){
	int i = nums.size() - 2;
	
	while (i >= 0 and nums[i+1] <= nums[i])
		i--;

	if (i >= 0){
		int j = nums.size() - 1;
		while (nums[j] <= nums[i])
			j--;
		swap(nums, i, j);
	}

	reverse(nums, i+1);
}

int main(){
	vector<int> v = {1};
		nextPermutation(v);
		for (int i: v) cout << i << " ";
	cout << endl;
	return 0;
}
