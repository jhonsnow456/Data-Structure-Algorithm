// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxtwobuysell(vector<int> &arr) {
    int first_buy = INT32_MIN;
    int first_sell = 0;
    int second_buy = INT32_MIN;
    int second_sell = 0;
       
        for(auto i: arr) {
            first_buy = max(first_buy,-i);
            first_sell = max(first_sell,first_buy+i);
            second_buy = max(second_buy,first_sell-i);
            second_sell = max(second_sell,second_buy+i);
        }
    
    return second_sell;
}

int main(){
    vector<int> arr = {2, 30, 15, 10, 8, 25, 80};
        cout << maxtwobuysell(arr) << endl;
    return 0;
}