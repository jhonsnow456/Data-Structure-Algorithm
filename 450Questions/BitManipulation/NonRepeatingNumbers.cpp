/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1/

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorVal = 0;
        
            for (auto num: nums)
                xorVal ^= num;
                
            
        int num1 = 0;
        int num2 = 0;
        
        int rmsb = xorVal & ~(xorVal - 1);
        
            for (auto num: nums){
                if (num & rmsb)
                    num1 ^= num;
                else
                    num2 ^= num;
            }
        
        vector<int> res = {num1, num2};
        
            sort(res.begin(), res.end());
            
        return res;
    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
