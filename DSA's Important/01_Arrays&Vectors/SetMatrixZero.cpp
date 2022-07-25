/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>

using namespace std;

struct coordinate{
    int X, Y;    
};

void modifymatrix(vector<vector<int>> &matrix, vector<coordinate> &markings){
    for (auto i: markings){
        int x = i.X; int y = i.Y;

        for (int j = 0; j < matrix.size(); j++){
            matrix[j][y] = 0;
        }

        for (int i = 0; i < matrix[0].size(); i++){
            matrix[x][i] = 0;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    vector<coordinate> markings;

        for (int i = 0 ; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0)
                    markings.push_back({i, j});
            }
        }

    modifymatrix(matrix, markings);
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
	vector<vector<int>> res = {{1, 2, 0}, {3, 0, 4}, {1, 2, 3}};

        setZeroes(res);
        
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
