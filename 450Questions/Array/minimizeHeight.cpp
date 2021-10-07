// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

#include <iostream>
#include <algorithm>

using namespace std;

// k = 3
// mi
// 3, 9, 12, 16, 20
//               mx

// pass 1: 3 Increase 9 decrease add a check if it exceed maxheight
// pass 2: 9 increase 12 decrease add a check if it lowers by minheight
// so on
int getMinDiff(int arr[], int n, int k){
    sort(arr, arr+n);
    
    int minElement, maxElement;
    int result = arr[n - 1] - arr[0];
    
    for(int i = 1; i <= n - 1; i++){
        if(arr[i] >= k){
            maxElement = max(arr[n - 1] - k, arr[i - 1] + k);
            minElement = min(arr[0] + k, arr[i] - k);
            
            result = min(result, maxElement - minElement);
        }
        else continue;
    }
    
    return result;
}

int main(){
    int K = 2, N = 4;
    int arr[] = {1, 5, 8, 10};

        cout << getMinDiff(arr, N, K) << endl;

    return 0;
}