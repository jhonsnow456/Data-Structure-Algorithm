/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<vector<int>> &board){
	for (auto row: board){
		for (auto col: row)
			cout << ((col == 1) ? 'Q' : 'x') << " ";
		cout << endl;
	}
}

bool canPlaceQueen(vector<vector<int>> &board, int row, int col){
	int N = board.size();

		// vertical check
		for (int vert = 0; vert < row; vert++)
			if (board[vert][col] == 1)
				return false;

		// left diag check
		for (int r = row, c = col; r >= 0 and c >= 0; r--, c--)
			if (board[r][c] == 1)
				return false;

		// right diag check
		for (int r = row, c = col; r >= 0 and c < N; r--, c++)
			if (board[r][c] == 1)
				return false;

	return true;	
}

bool solveNQueen(vector<vector<int>> &board, int row){
	int N = board.size();

		// base case reached the last row
		if (row == N){
			printBoard(board);
			return true;
		}

		// build our recurse cases
		// place queen in every row
		for (int col = 0; col < N; col++){

			// check if row, col is safe to 
			// place the queen 
			if (canPlaceQueen(board, row, col)){
				board[row][col] = 1; // placed the queen
				bool success = solveNQueen(board, row + 1);

				if (success)
					return true;

				// backtrack and remove the queen
				// from the board if failed
				board[row][col] = 0;
			}
		}

	return false;
}

int32_t main(){
	// write the code here
	int N; cin >> N;
	vector<vector<int>> board(N, vector<int> (N, 0)); // defining our board

		cout << (solveNQueen(board, 0) ? "Yes Possible!!" : "Not possible");

	return 0;
}
