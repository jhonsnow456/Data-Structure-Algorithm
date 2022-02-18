/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/

#include <bits/stdc++.h>

using namespace std;

pair<int, int> minPair(vector<int> &a1, vector<int> &a2){
	int diff = INT_MAX;
	int p1{0}, p2{0};

		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());

		for (int x: a1){
			auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();

			if (lb >= 1 and x - a2[lb - 1] < diff){
				diff = x - a2[lb - 1];
				p1 = a2[lb - 1];
				p2 = x; 
			}

			if (lb != a2.size() and a2[lb] - x < diff){
				diff = a2[lb] - x;
				p1 = x;
				p2 = a2[lb];
			} 
		}

	pair<int, int> res {p1, p2};

	return res;
}

int32_t main(){
	// write the code here
	vector<int> a1 {1, 3, 15, 11, 2};
	vector<int> a2 {23, 127, 235, 19, 8};

	auto res = minPair(a1, a2);

		cout << res.first << " " << res.second << endl;

	return 0;
}
