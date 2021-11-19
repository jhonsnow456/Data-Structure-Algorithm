// https://practice.geeksforgeeks.org/problems/next-permutation5226/1#

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
    
void reverse(vector<int>& arr, int start){
    int i = start, j = arr.size() - 1;
    
    while(i < j){
        swap(arr,i,j);
        i++; j--;
    }
}

vector<int> nextPermutation(int N, vector<int> arr){
    int i = N-2;
    while(i >=0 && arr[i+1] <= arr[i]) i--;
    
    if(i >= 0){
        int j = N - 1;
        while(arr[j] <= arr[i]) j--;
        swap(arr,i,j);
    }
    
    reverse(arr,i+1);
    return arr;
}

int main(){
    vector<int> nums = {1, 2, 3, 6, 5, 4};
        for (int i : nextPermutation(6, nums))
            cout << i << " ";
        cout << endl;
    return 0;
}
