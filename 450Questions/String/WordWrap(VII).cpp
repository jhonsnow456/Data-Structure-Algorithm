// https://practice.geeksforgeeks.org/problems/word-wrap1646/1

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int solve(vector<int> nums, int n, int i, int k, vector<int> &dp){
    
    if (dp[i] != -1) return dp[i]; // implemented memoization
    int ans = INT32_MAX, words = nums[i];

    int j = i;
    while (j < n and words <= k){
        if (j == n - 1)
            return 0;
        
        ans = min(ans, solve(nums, n, j + 1, k, dp) + (int)pow(k - words, 2));
        j++;
        words += nums[j] + 1;
    }

    return dp[i] = ans;
}

int solveWordWrap(vector<int> nums, int k){
    // Code here
    vector<int> dp(1001, -1);
    return solve(nums, nums.size(), 0, k, dp);
}

int main(){
    vector<int> nums = {3, 2, 2, 5};
    int k = 6;
    cout << solveWordWrap(nums, k) << endl;
    return 0;
}