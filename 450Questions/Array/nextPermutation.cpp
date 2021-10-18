// https://leetcode.com/problems/next-permutation/
// https://practice.geeksforgeeks.org/problems/next-permutation5226/1


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums){
	int size = nums.size();
	if (size == 1) return; // if the size is 1 then there is no possiblity of permutation
	
	int index = 1;
	int rightmostPeak = -1;
	
	while (index < size){
		if (nums[index] > nums[index-1])
			rightmostPeak = index;
		index++;
	}
	
	// It may be possible that the array is a decending array
	if (rightmostPeak == -1){
		for (int i = 0; i < size/2; i++)
			swap(nums[i], nums[size-i-1]);
		return;
	}

	// find the element in the range nums[rightmostPeak - 1] to nums[rightmostPeak] to the right 
	int min = nums[rightmostPeak];
	int search_index = rightmostPeak;

	for (index = rightmostPeak; index < size; index++){
		if (nums[index] > nums[rightmostPeak] and nums[index] < nums[search_index])
			search_index = index;
	}

	swap(nums[rightmostPeak-1], nums[search_index]);
	sort(nums.begin() + rightmostPeak, nums.end());
}

int main(){
	vector<int> v = {1};
		nextPermutation(v);
		for (int i: v) cout << i << " ";
	cout << endl;
	return 0;
}
