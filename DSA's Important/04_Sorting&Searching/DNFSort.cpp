/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/


// DNF Sort Algorithm
// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>

using namespace std;

vector<int> sortBalls(vector<int> &balls){
    //sort the balls in place in a single pass (O(N) time, 
    // O(1) space)
	int start = 0;
	int end = balls.size() - 1;
	int mid = 0;

		while (mid <= end){
			
			if (balls[mid] == 0) 
				swap(balls[start++], balls[mid++]);
			
			else if (balls[mid] == 1) 
				mid++;
			
			else if (balls[mid] == 2)
				swap(balls[mid], balls[end--]);
		}

    return balls;
}

int32_t main(){
	// write the code here
	int n; cin >> n;
	vector<int> balls(n);

		for (int &i: balls)
			cin >> i;

	vector<int> res = sortBalls(balls);

		for (auto i: res)
			cout << i << ", ";

	return 0;
}
