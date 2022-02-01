/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/


// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>

using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    int n = arr.size();

    	if (n == 1) return {0};

    int temp = 1;
    vector<int> output(n, 1);
		
    	for (int i = 0; i < n; i++){
    		output[i] = temp;
    		temp *= arr[i];
    		// cout << output[i] << ","; 
    	}

    	// cout << endl;

    	temp = 1;

    	for (int i = n - 1; i>= 0; i--){
    		output[i] *= temp;
    		temp *= arr[i];
    		// cout << output[i] << ",";
    	}

    	// cout << endl;

    return output;
}

int32_t main(){
	// write the code here
	vector<int> arr = {1, 2, 3, 4, 5};

		vector<int> res = productArray(arr);
		for (int &i: res) cout << i << " ";
		cout << endl;

	return 0;
}
