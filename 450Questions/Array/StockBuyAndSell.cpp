// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1/?page=1&company[]=Intuit%20&sortBy=submissions

#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector<vector<int>> stockBuySell(vector<int> &A, int n){
	vector<vector<int>> intervals;
	int i = 0;

		while (i < n - 1){
			vector<int> interval;

				// finding the local minima
				while ((i < n - 1) and (A[i + 1] <= A[i]))
					i++;

				if (i == n - 1)
					break;

				interval.push_back(i++);

				// finding the local maxima
				while ((i < n) and (A[i] >= A[i - 1]))
					i++;

				interval.push_back(i - 1);

			intervals.push_back(interval);		
		}

	return intervals;
}

void solve(){
	// write the code here
	int n; cin >> n;
	vector<int> A(n);

		for (int &i: A)
			cin >> i;

	vector<vector<int>> res = stockBuySell(A, n);

		for (auto i: res)
			cout << "Buy at: " << A[i[0]] << ", Sell At: " << A[i[1]] << endl;
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
