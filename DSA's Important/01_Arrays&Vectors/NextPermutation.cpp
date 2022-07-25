/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/next-permutation/ 

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void nextPermutation(vector<int> &nums){
	int n = nums.size(), idx1, idx2;

	for (idx1 = n - 2; idx1 >= 0; idx1--)
		if (nums[idx1] < nums[idx1 + 1])
			break;

	if (idx1 < 0){
		reverse(nums.begin(), nums.end());
	}else{
		for (idx2 = n - 1; idx2 > idx1; idx2--)
			if (nums[idx2] > nums[idx1])
				break;
		swap(nums[idx2], nums[idx1]);
		reverse(nums.begin() + idx1 + 1, nums.end());
	}
}

void solve(){
	// write the code here
	int n; cin >> n;
	vector<int> arr(n);

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		nextPermutation(arr);

		for (int i: arr) cout << i << " ";
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
