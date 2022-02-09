/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <bits/stdc++.h>

using namespace std;

pair<int,int> subarraySorting(vector<int> a){

	vector<int> b(a);

		sort(a.begin(), a.end());

	int start = 0, end = a.size() - 1;

		while (start < end and a[start] == b[start])
			start++;

		while (end > 0 and a[end] == b[end])
			end--;

	if (start == a.size() - 1) return {-1, -1};
	else return {start, end};
}

int32_t main(){
	// write the code here
	vector<int> a = {0, 1, 3, 2, 4};
	auto res = subarraySorting(a);

		cout << res.first << ", " << res.second << endl;

	return 0;
}
