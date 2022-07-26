/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void rotate(vector<vector<int>> &matrix){
	int n = matrix.size(), m = matrix[0].size();

	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for(int i = 0; i < n; i++)
		reverse(matrix[i].begin(), matrix[i].end());
}

void print(vector<vector<int>> &matrix){
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void solve(){
	// write the code here
	int n, m; cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int> (m));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> matrix[i][j];

		rotate(matrix);

	print(matrix);
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
