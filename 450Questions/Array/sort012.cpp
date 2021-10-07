// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

#include <iostream>
#include <algorithm>

using namespace std;

void sort012(int arr[], int n){
    int counter[3] = {};
    for (int i = 0; i < n; i++)
        counter[arr[i]]++;
        
    int pointer = 0;
    for (; pointer < counter[0]; pointer++)
        arr[pointer] = 0;
    for (pointer = counter[0]; pointer < counter[0] + counter[1]; pointer++)
        arr[pointer] = 1;
    for (pointer = counter[0] + counter[1]; pointer < n; pointer++)
        arr[pointer] = 2;
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n = 5;
    int arr[] = {0, 2, 1, 2, 0};

        sort012(arr, 5);
    return 0;    
}