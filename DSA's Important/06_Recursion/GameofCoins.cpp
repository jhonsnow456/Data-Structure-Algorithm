/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1/#

#include <bits/stdc++.h>

using namespace std;

int game(vector<int> &v, int start, int end){
	// base case
	if (start == end or start == end - 1)
		return max(v[start], v[end]);

	// option 1: to start from beginning
	int option1 = v[start] + min(game(v, start + 2, end), game(v, start + 1, end - 1));

	// option 2: start from end
	int option2 = v[end] + min(game(v, start + 1, end - 1), game(v, start, end - 2));

	return max(option1, option2);
}

int MaxValue(int n, vector<int> v){
	//Write your code here. 
	int res = game(v, 0, v.size() - 1);
	return res;
}

int32_t main(){
	// write the code here
	vector<int> v{8, 15, 3, 7};
	int N = v.size();

		cout << MaxValue(N, v);
	
	return 0;
}
