/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
    // write the code here
    int a; cin >> a;
    int cnt = 0;

    vector<int> f;

        for (int i = 1; i * i <= a; i++){
            if (a % i == 0){
                f.push_back(i);

                if (i * i < a)
                    f.push_back(a/i);
            }
        }

        for (int i = 0; i < f.size(); i++){
            string s = to_string(f[i]);
            bool ok = 1;
            int n = s.size();

                for (int i = 0; i < n; i++)
                    ok &= s[i] == s[n - i - 1];

            cnt += ok;
        }

    cout << cnt << endl;
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

