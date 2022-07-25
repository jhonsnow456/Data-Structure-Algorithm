/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int maxSubArray(vector<int> const &arr, vector<int> &subarray){
	int n = arr.size();
	int msf = INT_MIN, meh = 0, start = 0;

		for (int i = 0; i < n; i++){
			meh += arr[i];

			if (meh > msf){
				msf = meh;

				subarray.clear();
				subarray.push_back(start);
				subarray.push_back(i);
			}

			if (meh < 0){
				meh = 0;
				start = i + 1;
			}
		}

	return msf;
}

void print(vector<int> const &arr, vector<int> const &res){
	for (int i = res[0]; i <= res[1]; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void solve(){
	// write the code here
	vector <int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, -4};
	vector <int> subarray;

		int res = maxSubArray(arr, subarray);

	cout << "Longest Sum of subarray: " << res << endl;
	print(arr, subarray);	
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
