/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

pair<bool, int> findPath(int m, int n, int row, int col, vector<vector<int>> v, vector<vector<bool>> mat){
	if (row == m - 1 and col == n - 1) 
		return {true, 0};

	if (row >= m or row < 0 or col >= n or col < 0)
		return {false, -1};

	else{
		mat[row][col] = true;
		pair<bool, int> res{false, -1};

			// for downward
			if (row < m - 1 and v[row + 1][col] == 1 and mat[row + 1][col] == false){
				pair<bool,int> p1 = findPath(m, n, row + 1, col, v, mat);
	            
	            if(p1.first){
	                res.first=true;
	                res.second=max(res.second, p1.second);
	            }
			}

			// for rightward
			if(col < n - 1 and v[row][col+1] == 1 and mat[row][col+1] == false){
	            pair<bool,int> p2 = findPath(m, n, row, col + 1, v, mat);
	            
	            if(p2.first){
	                res.first = true;
	                res.second = max(res.second, p2.second);
	            }
	       }

	       // for upward
	       if(row > 0 and v[row - 1][col] == 1 and mat[row - 1][col] == false){
	            pair<bool,int> p3 = findPath(m, n, row - 1, col, v, mat);
	            
	            if(p3.first){
	                res.first = true;
	                res.second = max(res.second,p3.second);
	            }
	       }

	       //for leftward
	       if(col > 0 and v[row][col - 1] == 1 and mat[row][col - 1] == false){
	           pair<bool,int> p4 = findPath(m, n, row, col - 1, v, mat);
	           
	           if(p4.first){
	               res.first = true;
	               res.second = max(res.second,p4.second);
	           }
	       }

		// backtracking step
		mat[row][col] = false;
		res.second += 1;
		return res;	
	}
	
}

int findLongestPath(int m, int n, vector<vector<int>> v){
	vector<vector<bool>> mat(n, vector<bool> (n, false));

		pair<bool, int> res = findPath(m, n, 0, 0, v, mat);

	return res.second;
}

int32_t main(){
	// write the code here
	int N = 3, M = 3; 
	vector<vector<int>> v{{1, 1, 1}, {1, 1, 1}, {0, 0, 1}};

		cout << findLongestPath(N, M, v);

	return 0;
}
