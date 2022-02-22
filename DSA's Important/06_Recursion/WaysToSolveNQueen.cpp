/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

int cnt;

void printBoard(vector<vector<int>> &board){
	for (auto row: board){
		for (auto col: row)
			cout << ((col == 1) ? 'Q' : 'x') << " ";
		cout << endl;
	}
}

bool isSafe(vector<vector<int>> matrix, int row, int col){
	int N = matrix.size();

		// return false if two queens share the same column
		for (int vert = 0; vert < row; vert++)
			if (matrix[vert][col])
				return false;

		// return false if two queen share left diagonal
		for (int r = row, c = col; r >= 0 and c >= 0; r--, c--)
			if (matrix[r][c])
				return false;

		// return false if two queen share right diagonal
		for (int r = row, c = col; r >= 0 and c < N; r--, c++)
			if (matrix[r][c] == 1)
				return false;

	return true;
}

void solveNQueen(vector<vector<int>> &matrix, int row){
	int N = matrix.size();

		// if Nth queen is placed in the last row
		if (row == N){
			printBoard(matrix); cout << endl;
			cnt++;
			return;
		}

		for (int col = 0; col < N; col++){

			if (isSafe(matrix, row, col)){
				matrix[row][col] = 1; // place the queen
				solveNQueen(matrix, row + 1);
				matrix[row][col] = 0; // backtrack
			}
		}
}

int nQueen(int N){
	vector<vector<int>> matrix(N, vector<int> (N, 0));
		solveNQueen(matrix, 0);
	return cnt;
}

int32_t main(){
	// write the code here
	int N; cin >> N;

		cout << nQueen(N);

	return 0;
}
