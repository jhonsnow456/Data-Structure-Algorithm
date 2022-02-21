/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

void printSodukuMatrix(vector<vector<int>> &matrix){
	
	for (vector<int> row: matrix){
		for (int col: row)
			cout << col << " ";
		cout << endl;
	}

}

bool isPossible(vector<vector<int>> &matrix, int row, int col, int number){
	int N = sqrt(matrix.size());

	// check for row and col
	for (int idx = 0; idx < (int)(N * N); idx++)
		if (matrix[idx][col] == number or matrix[row][idx] == number)
			return false;

	// check for subgrid
	int subGridX = (row / N) * N;
	int subGridY = (col / N) * N;

		for (int xSubGrid = subGridX; xSubGrid < subGridX + 3; xSubGrid++)
			for (int ySubGrid = subGridY; ySubGrid < subGridY + 3; ySubGrid++)
				if (matrix[xSubGrid][ySubGrid] == number)
					return false;

	return true;
}

bool solveSoduku(vector<vector<int>> &matrix, int row, int col){
	int N = matrix.size();

		// hit the end of the row
		if (row == N){
			// print the matrix
			printSodukuMatrix(matrix);
			return true;
		}

		// hit the end of the col 
		if (col == N)
			// move the col again to start position
			return solveSoduku(matrix, row + 1, 0);

		// skip the cell filled with digit
		if (matrix[row][col] != 0)
			return solveSoduku(matrix, row, col + 1);

		// logic to fill the cell by trying 
		// all the avaiulable possiblity from 1 - N
		for (int number = 1; number <= N; number++){
			// check if it is possible to place a number 
			// or not 
			if (isPossible(matrix, row, col, number)){
				matrix[row][col] = number;
				bool isSubProblemSolved = solveSoduku(matrix, row, col + 1);

				if (isSubProblemSolved)
					return true;
			}
		}

		// backtracking logic
		matrix[row][col] = 0;

	return false;
}
 
int32_t main(){
	// write the code here
	vector<vector<int>> matrix{
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
	};

		if (!solveSoduku(matrix, 0, 0))
			cout << "Solution Does Not Exists" << endl;

	return 0;
}
