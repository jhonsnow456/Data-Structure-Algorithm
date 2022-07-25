/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void sort012(vector<int> &arr){
	int n = arr.size();
	int start = 0, mid = 0, end = n - 1;

	while (mid <= end){
		switch(arr[mid]){
			case 0: 
				swap(arr[start++], arr[mid++]);
				break;
			case 1: 
				mid++;
			case 2:
				swap(arr[mid], arr[end--]);
				break;
		}
	}
}

void print(vector<int> const &arr){
	for (int i: arr)
		cout << i << " ";
}

void solve(){
	// write the code here
	int n; cin >> n;
	vector<int> arr(n);

		for (int &i: arr) cin >> i;

		sort012(arr);

	print(arr);
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
