// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include <iostream>

using namespace std;

long long int maxSubarraySum(int arr[], int n){
    int curSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < n; i++){
        curSum = max(arr[i], curSum + arr[i]);
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}

int main(){
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);

        cout << "Maximum subarray sum: " << maxSubarraySum(a, n) << endl;
        
    return 0;
}