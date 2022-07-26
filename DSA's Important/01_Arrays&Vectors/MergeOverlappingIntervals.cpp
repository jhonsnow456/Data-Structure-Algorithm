/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector<pair<int, int>> merge(vector<pair<int, int>> &arr){
	int n = arr.size();
	
		sort(arr.begin(), arr.end());
	
	vector<pair<int, int>> ans;

		for (int i = 0; i < n; i++){
			if (ans.empty() or ans.back().second < arr[i].first)
				ans.push_back({arr[i].first, arr[i].second});
			else
				ans.back().second = max(ans.back().second, arr[i].second);
		}

	return ans;
}

void solve(){
	// write the code here
	vector<pair<int, int>> arr = {
		{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}
	};

	vector<pair<int, int>> res = merge(arr);

	cout << "Merged interval: " << endl;

	for (auto &itr: res)
		cout << itr.first << ", " << itr.second << endl;
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
