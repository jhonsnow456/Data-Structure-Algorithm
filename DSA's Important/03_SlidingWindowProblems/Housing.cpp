/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

/*
	Problem decribe the continuos plot segment in ehich you need to take  
	continuos sub plots in consideration of area k to fulfil your desire.
	Present the available plots to the buyer by presenting him sets of the 
	plot.
	
	INPUT: 
	[1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2]
	
	OUTPUT:
	2 5 
	4 6
	5 9
*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> housingPlots(vector<int> &plots, int k){
	vector<pair<int, int>> result;
	
	int n = plots.size(), area = 0;
	int prev = 0, next = 0;

		while (next < n){
			area += plots[next];
			next++;

			while (area > k and prev < next){
				area -= plots[prev];
				prev++;
			}

			if (area == k)
				result.push_back({prev, next - 1});
		}

	return result;
}

int32_t main(){
	// write the code here
	vector plots = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
	int k = 8;

		auto res = housingPlots(plots, k);

		for (auto i: res)
			cout << i.first << " " << i.second << endl;

	return 0;
}
