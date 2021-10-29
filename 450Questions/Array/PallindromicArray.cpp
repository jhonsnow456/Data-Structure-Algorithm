// https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1# 

#include <iostream>

using namespace std;

bool revNumber(int num){
    int n = num;
    int sum = 0;
    
    while (n != 0){
        int r = n % 10;
        sum = sum * 10 + r;
        n = n / 10;    
    }
    
    return num == sum;
}

int PalinArray(int a[], int n){  
    //add code here.
    for (int i = 0; i < n; i++){
        if (revNumber(a[i])) continue;
        else return 0;
    }
    return 1;
}

int main(){
    int testcase;
    cin >> testcase;

        while (testcase--){
            /* code */
            int size; cin >> size;
            int arr[size];

            for (int i = 0; i < size; i++)
                cin >> arr[i];

            cout << PalinArray(arr, size) << endl;
        }
        
    return 0;
}