// https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printCommonElements(vector<vector<int>> &v){
    int row = v.size();
    int col = v[0].size();

    unordered_map<int, int> mp;

    for (int i = 0; i < col; i++)
        mp[v[0][i]] = 1;
    
    for (int i = 1; i < row; i++){
        for (int j = 0; j < col; j++){
            if (mp[v[i][j]] == i){
                mp[v[i][j]] = i + 1;

                if (i == row - 1 and mp[v[i][j]] == row)
                    cout << v[i][j] << " ";
            }
        }
    }
}
    
int main(){
    vector<vector<int>> mat ={
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
        printCommonElements(mat);
    
    return 0;
}