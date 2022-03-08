/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> v) {
	//Write your code here.
	vector<int> res{1};
	stack<pair<int, int>> stk;
	stk.push({0, v[0]});
    
	    for (int i = 1; i < v.size(); i++){
    		
    		while (!stk.empty() and stk.top().second <= v[i])
    			stk.pop();
	    	
	    	if (!stk.empty())
	    		res.push_back(i - stk.top().first);

	    	else stk.top().first = i + 1;

	    	stk.push({i, v[i]});
	    }

	return res;
}

int32_t main(){
	// write the code here
	vector<int> stocks{100, 80, 60, 70, 60, 75, 85};
	vector<int> stock_spans = stockSpan(stocks);

		for (auto span: stock_spans)
			cout << span << ", ";

	return 0;
}
