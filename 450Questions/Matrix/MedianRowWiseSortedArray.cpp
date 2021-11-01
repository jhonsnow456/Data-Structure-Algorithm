// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// time O(r*c log(r*c)) complexity, space: o(r*c) complexity
int median1(vector<vector<int>> &matrix, int r, int c){
	vector<int> flatten_array;
	for (auto i: matrix)
		for (auto j: i)
			flatten_array.push_back(j);

	sort(flatten_array.begin(), flatten_array.end());
	
	return flatten_array[flatten_array.size() / 2];	
}

int median(vector<vector<int>> &matrix, int r, int c){
	// approch would be to find the min and max value in the matrix
	// since the array is sorted our task would be easy to find the max and min value
	int mn = INT32_MAX, mx = INT32_MIN;
	for (int i = 0; i < r; i++){
		mn = min(mn, matrix[i][0]);
		mx = max(mx, matrix[i][c-1]);
	}

	int target = (r * c + 1) / 2;

	// applying binary search algorithm 
	while (mn < mx){
		int mid = mn + (mx - mn) / 2;
		int count = 0;

		for (vector<int> array: matrix)
			count += upper_bound(array.begin(), array.end(), mid) - array.begin();
		
		if (count < target) mn = mid + 1;
		else mx = mid;
	}

	return mn;
}

int main(){
	vector<vector<int>> matrix = {
		{1, 3, 5},
		{2, 6, 9},
		{3, 6, 9}
	};

		cout << median(matrix, 3, 3) << endl;

	return 0;
}
