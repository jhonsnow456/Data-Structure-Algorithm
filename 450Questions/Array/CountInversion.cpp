// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <iostream>

using namespace std;

long long int merge_sort(long long int arr[], long long int temp[], int left, int right){
    long long int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
 
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);
 
        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

long long int merge(long long int arr[], long long int temp[], int left, int mid, int right){
    long long int i, j, k;
    long long int inv_count = 0;
 
    i = left;
    j = mid; 
    k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

long long int inversionCount(long long arr[], long long N){
    // int inv_count = 0;
    // for (int i = 0; i < N - 1; i++)
    //     for (int j = i+1; j < N; j++)
    //         if (arr[i] > arr[j]) inv_count++;
    // return inv_count;
    
    long long int temp[N];
    return merge_sort(arr, temp, 0, N - 1);
}

int main(){
    long long int temp[] = {2, 4, 1, 3, 5};
        cout << inversionCount(temp, sizeof(temp)/sizeof(temp[0])) << endl;
    return 0;
}