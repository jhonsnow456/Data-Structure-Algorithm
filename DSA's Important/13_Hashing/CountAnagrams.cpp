/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/count-total-anagram-substrings/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector<int> getHash(string s, int i, int j){
    vector<int> hash(26, 0);

        for (int k = i; k <= j; k++)
            hash[s[k] - 'a']++;

    return hash;
}

int anagrams_substring(string &s){

    map<vector<int>, int> mp;

    for (int i = 0; i < s.length(); i++){
        for (int j = i; j < s.length(); j++){
            vector<int> hash = getHash(s, i, j);
            mp[hash]++;
        }
    }

    int ans = 0;

    for (auto i: mp){
        int freq = i.second;
        ans += (freq) * (freq - 1) / 2; // nC2;
    }

    return ans;
}

void solve(){
    // write the code here
    string s; cin >> s;
    cout << anagrams_substring(s) << endl;
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
