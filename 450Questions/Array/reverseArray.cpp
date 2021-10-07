// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include <iostream>
#include <algorithm>

using namespace std;

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void reverseArray(int arr[], int n){
    int start = 0;
    int end = n - 1;

    while (start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    } 

    display(arr, n);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

        reverseArray(arr, n);

    return 0;
}