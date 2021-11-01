// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix){
	int result = -1, row = 0;
	int cnt = 0;
		for (vector<int> array: matrix){
			int present_count = count(array.begin(), array.end(), 1);
			if (cnt < present_count){
				cnt = present_count;
				result = row;
			}
			row++;
		}
	return result;
}

int main(){
	vector<vector<int>> matrix = {
		{0, 1, 1, 1},
		{0, 0, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 0},
	};

		cout << rowWithMax1s(matrix) << endl;

	return 0;
}
