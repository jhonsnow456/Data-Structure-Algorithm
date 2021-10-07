// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//                      i
// -1, -3, -7, 4, 5, 6, 2, 8, 9
//             j

void rearrange(int arr[], int n){
    int j = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] < 0){
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }

    printArray(arr, n);
}

int main(){
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);

    return 0;
}