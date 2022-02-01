/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

//  https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
	int n = height.size();
	vector<int> leftMaxHeight(n), rightMaxHeight(n);

		leftMaxHeight[0] = height[0];
		rightMaxHeight[n - 1] = height[n - 1];

		for (int i = 1; i < n; i++)
			leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i]);

		for (int i = n - 2; i >= 0; i--)
			rightMaxHeight[i] = max(rightMaxHeight[i + 1], height[i]);


	int res = 0;

		for (int i = 0; i < n; i++){
			res += min(leftMaxHeight[i], rightMaxHeight[i]) - height[i];
		}	

	return res;
}

int32_t main(){
	// write the code here
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

		cout << trap(height) << endl;

	return 0;
}
