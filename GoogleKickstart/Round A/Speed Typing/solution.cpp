/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	string I, P;
	cin >> I >> P;

	int iLength = I.length() - 1, pLength = P.length() - 1;
	int diff = pLength - iLength;
	int res = diff;

		while(iLength >= 0 or pLength >= 0){
			iLength = I.length() - 1;
			pLength = P.length() - 1;

			if (I[iLength] == P[pLength]){
				I.pop_back();
				P.pop_back();
			}else{
				P.pop_back();
				diff--;
			}

			if (diff < 0) {
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}

	cout << res << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}

