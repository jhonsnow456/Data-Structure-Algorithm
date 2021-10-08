// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findDuplicate(int nums[], int n) {
    unordered_map<int, int> h;
    int res;
    
    for (int i = 0; i < n; i++)
        h[nums[i]]++;
        
    for (auto i: h)
        if (i.second > 1) res = i.first;
    
    return res;
}

int main(){
    int nums[] = {1,3,4,2,2};
    int n = sizeof(nums) / sizeof(nums[0]);

        cout << findDuplicate(nums, n) << endl;

    return 0;
}