// https://practice.geeksforgeeks.org/problems/edit-distance3702/1#

#include <iostream>

using namespace std;

// Approch 1 using recursion 
int minCost(int x, int y, int z){
    return min(min(x, y), z);
}

// int editDistance(string s, string t){
//     int n = s.length();
//     int m = t.length();
    
//     if (n == 0) return m;
//     if (m == 0) return n;

//     // if both the strings are same 
//     if (s[n - 1] == t[m - 1]) return editDistance(s.substr(0, n-1), t.substr(0, m-1)); 

//     return 1 + minCost(
//         editDistance(s.substr(0, n-1), t.substr(0, m)), // removing the character
//         editDistance(s.substr(0, n), t.substr(0, m-1)), // adding the character
//         editDistance(s.substr(0, n-1), s.substr(0, m-1)) // transtioning the character
//         );
// }


// Approch 2 : dp approch 
int editDistance(string s, string t){
    int n = s.length();
    int m = t.length();

    int dp[n+1][m+1];

        for (int  i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + minCost(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }

    return dp[n][m];
}

int main(){
    string s1 = "dbb", s2 = "fdfaccddfac";
        cout << editDistance(s1, s2) << endl; 
    return 0;
}