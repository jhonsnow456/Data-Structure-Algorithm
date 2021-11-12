#include <iostream>

using namespace std;

int LongestRepeatingSubsequence(string str){
    int size = str.length();
    int dp[size+1][size+1];

    for (int i = 0; i <= size; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    } 

    for (int i = 1; i <= size; i++){
       for (int j = 1; j <= size; j++){
            if (str[i-1] == str[j-1] and i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
       }
    }

    return dp[size][size];
}

int main(){
    string str = "aab";
        cout << LongestRepeatingSubsequence(str) << endl;    
    return 0;
}