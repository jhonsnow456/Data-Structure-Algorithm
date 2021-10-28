// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include <iostream>

using namespace std;

long long trappingWater(int arr[], int n){
    // code here
    int leftMaxHeight[n], rightMaxHeight[n];

    leftMaxHeight[0] = arr[0];
    for (int i = 1; i < n; i++)
        leftMaxHeight[i] = max(arr[i], leftMaxHeight[i - 1]);

    rightMaxHeight[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMaxHeight[i] = max(arr[i], rightMaxHeight[i + 1]);

    long long int sumofTrappedwater = 0;

    for (int i = 0; i < n; i++)
        sumofTrappedwater += min(leftMaxHeight[i], rightMaxHeight[i]) - arr[i];

    return sumofTrappedwater;
}

int main(){
    int N = 6;
    int arr[] = {3,0,0,2,0,4};

        cout << trappingWater(arr, N) << endl;
    return 0;
}