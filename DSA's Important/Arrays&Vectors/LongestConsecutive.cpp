/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_set<int> hashmap;
	int n = nums.size();
	int length = 0;

		for (int &num: nums)
			hashmap.insert(num);

		for (int &num: nums){
			int parent = num - 1;

				if (hashmap.find(parent) == hashmap.end()){
					// find the entire chain
					int next_num = num + 1;
					int cnt = 1;

					while (hashmap.find(next_num) != hashmap.end()){
						next_num++;
						cnt++;
					}

					length = max(length, cnt);
				}
		}

	return length;
}

int32_t main(){
	// write the code here
	vector<int> arr = {100,4,200,1,3,2};
		cout << longestConsecutive(arr) << endl;
	return 0;
}
