/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include<bits/stdc++.h>

using namespace std;

int sum(vector<int> v, int row, int col){
	int res = 0;

		for (int k = row; k < col; k++)
			res += v[k];
	
	return res;
}

int calc(vector<int> v, int start, int end, int k){
	if (end - start + 1 < 0) return 0;

	int res = INT_MIN;

		for (int row = 0; row <= k; row++){
			int ans = sum(v, start, start + row) + sum(v, end - k + row + 1, end + 1);
			int op = INT_MAX;

				for (int col = 0; col <= k; col++)
					op = min(op, calc(v, start + row + col, end - k + row - k + col, k));

			return max(res, ans + op);
		}

	return res;
}

int MaxValue(int N, vector<int> v, int k){
    //Write your code here.
    int res = calc(v, 0, N - 1, k);
    return res;
}
int32_t main(){
	// write the code here
	int N, K; cin >> N >> K;
	vector<int> A(N);

		for (int &val: A)
			cin >> val;

		cout << MaxValue(N, A, K) << endl;

	return 0;
}
