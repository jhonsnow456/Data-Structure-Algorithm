// https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long maxAreaHist(vector<int> &array, int N){
	long long area = 0, maxArea = 0;
	int i = 0;

	stack<int> s;

	while (i < N){
		if (s.empty() or array[s.top()] <= array[i])
			s.push(i++);
		else {
			int y = s.top();
			s.pop();

			if (s.empty()) area = array[y] * i;
			else area = array[y] * (i - s.top() - 1);

			maxArea = max(area, maxArea);
		}
	}

	while (!s.empty()){
		int y = s.top();
		s.pop();

		if (s.empty()) area = array[y] * i;
		else area = array[y] * (i - s.top() - 1);

		maxArea = max(area, maxArea);
	}

	return maxArea;
}

int maxArea(vector<vector<int>> &M, int n, int m) {
	// creating the histogram in the array
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (i != 0){
				if (M[i][j] != 0)
					M[i][j] += M[i - 1][j];
				else M[i][j] = 0;
			}		
		}
	}

	// calculating the maximum area
	int res = 0;
	for (int i = 0; i < n; i++){
		int k = maxAreaHist(M[i], m);
		res = max(res, k);
	}

	return res;
}

int main(){
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

        cout << maxArea(M, 4, 4) << endl;

    return 0;
}
