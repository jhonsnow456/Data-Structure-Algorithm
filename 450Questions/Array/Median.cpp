// https://practice.geeksforgeeks.org/problems/find-the-median0527/1#

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find_median(vector<int> v){
    // Code here.
    sort(v.begin(),v.end());
    int n = v.size();
    
    if(n%2 != 0)
        return v[(n)/2];
    
    return (v[n/2]+v[(n/2)-1])/2;
}

int main(){
    vector<int> v = {90, 100, 78, 89, 67};
        cout << "Median: " << find_median(v) << endl;
    return 0;
}