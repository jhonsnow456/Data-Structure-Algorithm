/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007

struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
 
TrieNode *root;

bool searchString(string str){
    TrieNode *curr = root;
    int n = str.length();
    
	    for(int i=0;i<n;i++){
	        int idx = str[i] - 'a';
	        
	        if(curr->child[idx] == NULL)
	            return false;

	        curr = curr->child[idx];
	    }

    return curr->isEnd;
}
 
void insertString(string str){
    TrieNode *curr = root;
    int n = str.length();
    
    for(int i=0; i < n; i++){
        int idx = str[i] - 'a';

        if(curr->child[idx] == NULL)
            curr->child[idx] = new TrieNode();

        curr = curr->child[idx];
    }

    curr->isEnd = true;
}
 
void solve(){
    string str; cin>>str;
 
    int n; cin>>n;
    root = new TrieNode();
 
    for(int i = 0;i < n;i++){
        string st; cin>>st;
        insertString(st);
    }
 
    int len = str.length();

    vector<int> dp(len+1);
		
		//step to remember it signify that there exist an 
		// ans to the problem
    dp[len] = 1; 
 
	    for(int i = len - 1; i >= 0; i--){
	        TrieNode *test = root;
	        
	        for(int j = i; j < len; j++){
	            int idx = str[j] - 'a';

	            if(test->child[idx] == NULL)
	                break;

	            test = test->child[idx];

	            if(test->isEnd){
	                dp[i] = dp[i] % mod + dp[j + 1] % mod;
	                dp[i] = dp[i] % mod;
	            }
	        }
	    }
    
    cout << dp[0] << endl;
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
