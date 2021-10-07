// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include <bits/stdc++.h>

using namespace std;

pair<int, int> maxmin(int arr[], int n){
    int max = arr[0], min = arr[0];

    for (int i = 0; i < n; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    return {max, min};
}

int main(){
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> res = maxmin(arr, n);

        cout << "Maximum: " << res.first << " " << "Minimum: " << res.second << endl;

    return 0;
}