// https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int i = 0;
	int m = matrix.size();
	int n = matrix[0].size();

	while (i < m && matrix[i][n - 1] < target) 
		i++;

	int low = 0;
	int high = n - 1;

	while (low < high){
		int mid = low + (high - low) / 2;

		if (matrix[i][mid] == target)
			return true;
		if (target < matrix[i][mid])
			high = mid - 1;
		else 
			low = mid + 1; 
	}

	return false;
}

int main(){
	vector<vector<int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	}; 

		cout << searchMatrix(matrix, 3) << endl;

    return 0; 
}
