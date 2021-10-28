// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void threeWayPartition(vector<int>& array,int a, int b){
    // code here 
    sort(array.begin(), array.end());
}

int main(){
    vector<int> A = {1, 2, 3, 3, 4};
    
    int a, b;
    cin >> a >> b;
        
        threeWayPartition(A, a, b);

    return 0;
}