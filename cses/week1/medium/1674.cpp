/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void dfs(vector<int> emp[], int n, int curr, int prev, vector<int> &count){
	// initializing each index with 1 
	// during head recursion

	count[curr] = 1; 

	for (auto i: emp[curr]){ 
		dfs(emp, n, i, curr, count);
		//storing the count of subordinate
		// during the tail recursion
		count[curr] += count[i]; 
	}

}

void solve(){
	// write the code here
	int n; cin >> n;
	vector<int> employee[n + 2];
	vector<int> res(n + 1, 0);

		for (int i = 0; i < n; i++){
			int k; cin >> k;

			if (i + 2 <= n)
				employee[k].push_back(i + 2);
		}

	dfs(employee, n, 1, 0, res);

	for (int i = 1; i <= n; i++)
		cout << res[i] - 1 << " ";
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

