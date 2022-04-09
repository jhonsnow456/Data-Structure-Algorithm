/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int
 
bool isValid(vector<string> &matrix, vector<vector<bool>> &vis, int row, int col){
	if (row < 0 or row >= matrix.size() or col < 0 or col >= matrix[0].size()) return false;
	if (matrix[row][col] == '#' or vis[row][col]) return false;
	return true;
}
 
void dfs(vector<string> &matrix, vector<vector<bool>> &vis, int row, int col){
	vis[row][col] = true;
 
	if (isValid(matrix, vis, row - 1, col))
		dfs(matrix, vis, row - 1, col);
 
	if (isValid(matrix, vis, row + 1, col))
		dfs(matrix, vis, row + 1, col);
 
	if (isValid(matrix, vis, row, col - 1))
		dfs(matrix, vis, row, col - 1);
 
	if (isValid(matrix, vis, row, col + 1))
		dfs(matrix, vis, row, col + 1);
}
 
void solve(){
	// write the code here
	int n, m;
	cin >> n >> m;
 
		vector<string> matrix;
		vector<vector<bool>> visited(n, vector<bool> (m));
 
 
		for (int i = 0; i < n; i++){
			string s; cin >> s;
			matrix.push_back(s);
 
			for (int j = 0; j < m; j++)
				visited[i][j] = (s[j] == '#');
		}
 
	int cnt = 0;
 
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (matrix[i][j] == '.' and visited[i][j] == false)
					dfs(matrix, visited, i, j), cnt++;
			}
		}
 
	cout << cnt << endl;		
 
}
 
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int test_case = 1;
    // std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			// std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}
