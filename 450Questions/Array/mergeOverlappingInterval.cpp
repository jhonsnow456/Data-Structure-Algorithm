// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    int index = 0;
    
    vector<vector<int>> result;

    for (int i = 1; i < n; i++){
        if (intervals[index][1] >= intervals[i][0]){
            intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            intervals[index][0] = min(intervals[index][0], intervals[i][0]);
        }else{
            index++;
            intervals[index] = intervals[i];
        }
    }

    for (int i = 0; i <= index; i++)
        result.push_back({intervals[i][0], intervals[i][1]});

    return result;
}

int main(){
    vector<vector<int>> arr = {{1,4},{4,5}};
    vector<vector<int>> res = merge(arr);

        for (auto i: res)
            cout << "["<< i[0] << "," << i[1] << "]";

    return 0;
}