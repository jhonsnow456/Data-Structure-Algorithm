/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int search(vector<int> arr, int target){
	int n = arr.size();
	int low = 0, high = n - 1;

		while (low <= high){
			int mid = (high + low) >> 1;

			if (arr[mid] == target){
				return mid;
			}


			// left part is sorted
			if (arr[low] <= arr[mid]){
				if (target >= arr[low] and target <= arr[mid]){
					high = mid - 1;
				}else{
					low = mid + 1;
				}
			}else{
				if (target >= arr[mid] and target <= arr[high]){
					low = mid + 1;
				}else{
					high = mid - 1;
				}
			}
		}

	return -1;
}

void solve(){
	// write the code here
	int n, x; cin >> n >> x;
	vector <int> arr(n);

		for (int &i: arr)
			cin >> i;


	cout << search(arr, x) << endl;
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
