/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

bool isSafe(int N, vector<vector<char>> &maze, vector<int> &res, int row = 0, int col = 0){

		if (row == N and col == N) return true; // reach the end of the row
		if (row == N + 1 or col == N + 1) return false;

		// check leftward
		if (col != N and maze[row][col + 1] != 'X'){
			if (isSafe(N, maze, res, row, col + 1)){
				int cost = (row * (N + 1)) + col + 2;
				res.push_back(cost);
				return true;
			}
		}

		// check downward
		if (row != N and maze[row + 1][col] != 'X'){
			if (isSafe(N, maze, res, row + 1, col)){
				int cost = ((row + 1) * (N + 1)) + col + 1;
				res.push_back(cost);
				return true;
			}
		}

	return false;
}

vector<int> findPath(int N, vector<vector<char>> &maze){
	vector<int> path;

		isSafe(N - 1, maze, path);
		path.push_back(1);
		reverse(path.begin(), path.end());

	return path;    
}

int32_t main(){
	// write the code here
	int N; cin >> N;
	vector<vector<char>> maze(N, vector<char> (N));

		for (vector<char> &row: maze)
			for (char &col: row)
				cin >> col;
	
	vector<int> res;

		res = findPath(N, maze);

		for (auto val: res)
			cout << val << ", ";

	return 0;
}
