// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

#include <iostream>
#include <algorithm>

using namespace std;

int smallestSubWithSum(int arr[], int n, int x){
    // Your code goes here
    int sum = 0;
    int ans = INT32_MAX;

    int start = 0;
    for (int end = 0; end < n; end++){
        sum += arr[end];
        
        while (sum > x and start <= end){
            ans = min(ans, (end - start) + 1);
            sum -= arr[start++];
        }
    }

    return ans;   
}

int main(){
    int A[] = {1, 4, 45, 6, 0, 19};
    int N = sizeof(A) / sizeof(A[0]);
    int x  =  51;

        cout << smallestSubWithSum(A, N, x) << endl;

    return 0;
}