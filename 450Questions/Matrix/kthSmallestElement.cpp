// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(vector<vector<int>> &mat, int k){
    //Your code here
    vector<int> res;
    int n = mat.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res.push_back(mat[i][j]);
    
    sort(res.begin(), res.end());
    
    return res[k-1];
}

int main(){
    vector<vector<int>> m = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94 }
    };

    int k = 7;

        cout << kthSmallest(m, k) << endl;

    return 0;
}