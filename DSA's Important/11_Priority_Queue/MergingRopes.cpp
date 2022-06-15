/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < N; i++){
			int k; cin >> k;
			pq.push(k);
		}

	int res = 0;

		while(pq.size() > 1){
			int first = pq.top();
			pq.pop();
			int second = pq.top();
			pq.pop();
			
			res += first + second;
			pq.push(first + second);
		}

	cout << res << endl;
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
