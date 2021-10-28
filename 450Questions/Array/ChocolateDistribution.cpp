// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long findMinDifference(vector<long long int> a, long long n, long long m){
    sort(a.begin(), a.end());
    long long int ans = INT32_MAX;

    for (int i = 0; i <= n - m; i++)
        ans = min(a[m + i - 1] - a[i], ans);
    
    return ans;
}

int main(){
    int N = 7, M = 3;
    vector<long long int> A = {7, 3, 2, 4, 9, 12, 56};
        cout << findMinDifference(A, N, M) << endl;
    return 0;
}