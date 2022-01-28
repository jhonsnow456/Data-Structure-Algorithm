/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& num) {
	sort(num.begin(), num.end());

	vector<vector<int>> result;     
    int n = num.size();

        for (int i = 0; i < n - 2; i++) {
            
            if (i == 0 or (i > 0 and num[i] != num[i-1])) {
                 
                int j = i + 1, k = n - 1, sum = 0 - num[i];
                
                while (j < k) {
                    if (num[j] + num[k] == sum) {
                        
                        result.push_back({num[i], num[j], num[k]});
                        
                        while (j < k and num[j] == num[j + 1]) j++;
                        while (j < k and num[k] == num[k - 1]) k--;
                        
                        j++; k--;
                    } 
                    else if (num[j] + num[k] < sum) j++;
                    else k--;
               }
            }
        }
        
    return result;
}

int32_t main(){
	// write the code here
	vector<int> arr = {-1,0,1,2,-1,-4};

		auto result = threeSum(arr);

		for (auto i: result){
			cout << "{";
			for (auto j: i)
				cout << j << ",";
			cout << "}" << endl;
		}

	return 0;
}
