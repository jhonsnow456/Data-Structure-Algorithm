/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define mod (int)(1e9 + 7)
 
void solve(){
	// write the code here
	int n, sum; cin >> n >> sum;
	vector<int> coins(n);
 
		for (int &coin: coins) cin >> coin;
 
	vector<int> numberOfCoinCombination(sum + 1);
	numberOfCoinCombination[0] = 1;
 
		for (int value = 1; value <= sum; value++){
			for (int coin = 0; coin < n; coin++){
				if (value - coins[coin] >= 0){
					numberOfCoinCombination[value] += numberOfCoinCombination[value - coins[coin]];
					numberOfCoinCombination[value] %= mod;
				}
			}
		}
 
	cout << numberOfCoinCombination[sum] << endl;
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
