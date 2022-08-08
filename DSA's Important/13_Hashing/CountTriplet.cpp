/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.hackerrank.com/challenges/count-triplets-1/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

#define int long long int

long count_triplet(vector<long> &arr, int r){
	int ans = 0, n = arr.size();
	unordered_map<long, long> left, right;

		for(int x: arr)
			right[x]++;

		for (int i = 0; i < n; i++){
			right[arr[i]]--;

			if (arr[i] % r == 0){
				long b = arr[i];
				long a = arr[i] / r;
				long c = arr[i] * r;

				ans += (left[a] * right[c]);
			}

			left[arr[i]]++;
		}
	return ans;
}

void solve(){
	// write the code here
	long n, r; cin >> n >> r;
	vector<long> arr(n);

		for (long &x: arr)
			cin >> x;

	cout << count_triplet(arr, r) << endl;
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

