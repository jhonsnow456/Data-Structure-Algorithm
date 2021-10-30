// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

#include <iostream>
#include <vector>

using namespace std;

int findMaxValue(vector<vector<int>> &v){
    vector<vector<int>> maxArray;
    vector<int> zeroArray(v[0].size());

    for (int i = 0; i < v.size(); i++)
        maxArray.push_back(zeroArray);

    int maxValue = INT32_MIN;
    int N = v.size();

    maxArray[N - 1][N - 1] = v[N - 1][N - 1];

    int maxv = v[N - 1][N - 1];
    for (int j = N - 2; j >= 0; j--){
        if (v[N - 1][j] > maxv)
            maxv = v[N - 1][j];
        maxArray[N - 1][j] = maxv;
    }

    maxv = v[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--){
        if (v[i][N - 1] > maxv)
            maxv = v[i][N - 1];
        maxArray[i][N - 1] = maxv;
    }

    for (int i = N - 2; i >= 0; i--){
        for (int j = N - 2; j >= 0; j--){
            if (maxArray[i + 1][j + 1] - v[i][j] > maxValue)
                maxValue = maxArray[i + 1][j + 1] - v[i][j];

            maxArray[i][j] = max(v[i][j], max(maxArray[i][j + 1], maxArray[i + 1][j]));
        }
    }

    return maxValue;
}

int main(){
    
    vector<vector<int>> mat = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};

    cout << "Maximum Value is: " << findMaxValue(mat) << endl;

    return 0;
}
