/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/

#include <bits/stdc++.h>

using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int apointer = 0, bpointer = 0;
    int res = INT32_MAX;

    vector<pair<int, int>> result;

    	while (apointer < a.size() and bpointer < b.size()){
    		if (abs(a[apointer] - b[bpointer]) < res){
    			res = abs(a[apointer] - b[bpointer]);
    			result.push_back({a[apointer], b[bpointer]});
    		}
    		
    		if (a[apointer] < b[bpointer]) apointer++;
    		else bpointer++;
    	}   

    return result[result.size() - 1];
}

int32_t main(){
	// write the code here
	vector<int> a = {23, 5, 10, 17, 30};
	vector<int> b = {26, 134, 135, 14, 19};

		auto res = minDifference(a, b);
		cout << res.first << ", " << res.second;
	
	return 0;
}
