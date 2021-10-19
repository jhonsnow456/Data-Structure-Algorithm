// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT32_MAX;
    int maxProfit = 0;
    
    for (int i = 0; i < prices.size(); i++){
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if(prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }
    
    return maxProfit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
        cout << maxProfit(prices) << endl;
    return 0;
}