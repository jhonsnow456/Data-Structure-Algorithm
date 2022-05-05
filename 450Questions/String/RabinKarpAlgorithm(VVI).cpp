/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define d 256
#define mod 101

// assumtion is made that the string contains only the 
// lower case charcters

void solve(){
	// write the code here
	string s, p; 
	cin >> s >> p;

	int n = s.length();
	int m = p.length();

	int sh = 0, ph = 0, h = 1;

		for (int i = 0; i < m - 1; i++){
			h = (h * d) % mod;  
		}

		for (int i = 0; i < m; i++){
			sh = (sh * d + s[i]) % mod;
			ph = (ph * d + p[i]) % mod;
		}

		for (int i = 0; i < n; i++){

			if (sh == ph){
				bool f = 0;

					for (int j = 0; j < m; j++){
						if (s[i + j] != p[j]){
							f = 1;
							break;
					}

				}

				if (!f) cout << i << endl;
			}


			if (i < n - m){
				// s[i] denotes character to be removed
				// s[i + m] denotes charatcer to be added
				// h = pow(d, m - 1)
				sh = ((sh - s[i] * h) * d + s[i + m]) % mod;
				if(sh < 0) sh = sh + mod;
			}
		}
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
