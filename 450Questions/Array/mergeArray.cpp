// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr1[], int n, int arr2[], int m){
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    for (int j = 0; j < m; j++)
        cout << arr2[j] << " ";
}

void merge(int arr1[], int arr2[], int n, int m) {
	// code here
    int f = n - 1;
    int l = 0;

    while(f >= 0 && l < m){
        if(arr1[f] >= arr2[l])
            swap(arr1[f], arr2[l]);
        f--; l++;
    }   

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    printArray(arr1, n, arr2, m);
}

int main(){
    int N = 2, M = 3;
    int arr1[] = {10, 12};
    int arr2[] = {5, 18, 20};

        merge(arr1, arr2, N, M);

    return 0;
}