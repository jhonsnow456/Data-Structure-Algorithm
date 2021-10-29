// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

#include <iostream>

using namespace std;

int minSwap(int arr[], int n, int k) {
    int cnt = 0;
    int ans = INT32_MAX;

    for(int i = 0; i < n; i++)
        if (arr[i] <= k) cnt++;
    
    int bad = 0;
    for(int i = 0; i < cnt; i++){
        if (arr[i] > k) bad++;
        ans = bad;
    }

    for (int i = 0; i < n - cnt; i++){
        if (arr[i] > k) bad--;
        if (arr[i + cnt] > k) bad++;

        ans = min(ans, bad);
    }

    return ans;
}

int main(){
    int arr[] = {2, 1, 5, 6, 3}; 
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

        cout << minSwap(arr, N, K) << endl;
    
    return 0;
}