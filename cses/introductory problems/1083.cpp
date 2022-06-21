/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
    // write the code here
    int n, sum = 0; cin >> n;
        
        for (int i = 1; i < n; i++){
            int k; cin >> k;
            sum += k;
        }

    cout << (n * (n + 1)) / 2 - sum;
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

