// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1# 

#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void rotate(int arr[], int n){
    int temp = arr[n-1];
    
    for (int i = n - 1; i > 0; i--)
        arr[i] = arr[i-1];    

    arr[0] = temp;

    printArray(arr, n);
}

int main(){
    int N = 5;
    int A[] = {1, 2, 3, 4, 5};

        rotate(A, N);

    return 0;
}