/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector<vector<int>> generate_pascal_triangle(int rows){
	vector<vector<int>> pascal_triangle(rows);

		for (int i = 0; i < rows; i++){
			pascal_triangle[i].resize(i + 1);
			pascal_triangle[i][0] = pascal_triangle[i][i] = 1;

			for (int j = 1; j < i; j++)
				pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
		}

	return pascal_triangle;
}

void print(vector<vector<int>> const &res){
	for (auto i: res){
		for (auto j: i)
			cout << j << " ";
		cout << endl;
	}
}

void solve(){
	// write the code here
	int no_rows; cin >> no_rows;
	vector<vector<int>> res = generate_pascal_triangle(no_rows);

	print(res);
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
