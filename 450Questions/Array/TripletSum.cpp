// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

#include <iostream>
#include <algorithm>

using namespace std;

bool find3Numbers(int arr[], int n, int X){
    //Your Code Here
    sort(arr, arr+n);
        for (int i = 0; i < n -2; i++){
            int start = i + 1;
            int end = n - 1;
            while (start < end){
                if (arr[i] + arr[start] + arr[end] == X) return true;
                else if (arr[i] + arr[start] + arr[end] < X) start++;
                else if (arr[i] + arr[start] + arr[end] > X) end--;
            }
        }
    return false;
}

int main(){
    int arr[] = {1, 2, 3, 6, 7, 4};
    int size = 6;
    int x = 51;

    cout << find3Numbers(arr, size, x) << endl;

    return 0;
}