/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

// Method 1
vector<int> maxInWindow(vector<int> &input, int k){
	vector<int> result;
	deque<int> Q;
	int next = 0;

		// this look accounts for the (n - 1)th maximum
		// in the input array
		while (next < input.size()){
			if (Q.size() == k){
				int max = *max_element(Q.begin(), Q.end());
				result.push_back(max);
				Q.pop_front();
			}
			Q.push_back(input[next]);
			next++;
		}

		// this condition accounts for the last nth 
		// maximum
		if (Q.size() == k){
			int max = *max_element(Q.begin(), Q.end());
			result.push_back(max);
			Q.pop_front();
		}

	return result;
}


// METHOD 2
vector<int> maxInWindow(vector<int> input, int k){
	// multiset stores the element in the form of priority_queue 
	// and also can store the duplicate element.
	multiset<int>s;
	vector<int> result;
	    
	    for(int i = 0; i < k; i++)
	    	s.insert(input[i]);

	int n = input.size();
	    
	    	result.push_back(*s.rbegin());
	    
	    for(int i = 1; i < n - k + 1; i++){
	        // remove the ith element
	        auto it = s.find(input[i - 1]);
        	s.erase(it);

        	// insert the element into the multiset 
        	s.insert(input[i + k - 1]);
        	result.push_back(*s.rbegin());
	    }

    return result;
}

int32_t main(){
	// write the code here
	int k = 3;
	vector<int> input = {1, 2, 3, 1, 4, 5, 2, 3, 6};
		
		auto res = maxInWindow(input, k);

		for (auto i: res)
			cout << i << ",";

	return 0;
}
