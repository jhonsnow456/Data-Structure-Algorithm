// https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	for (vector<int> i: matrix){
		bool found = binary_search(i.begin(), i.end(), target);
		if (found) return true;
	}

	return false;
}

int main(){
	vector<vector<int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	}; 

		cout << searchMatrix(matrix, 1) << endl;

    return 0; 
}
