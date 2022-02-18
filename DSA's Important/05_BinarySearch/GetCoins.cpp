/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

bool divide(vector<int> &arr, int k, int limit){
	int cnt = 0;
	int curSum = 0;

		for (int i = 0; i < arr.size(); i++){
			if (curSum + arr[i] >= limit){
				cnt++;
				curSum = 0;
			}else{
				curSum += arr[i];
			}
		}

	return cnt >= k;
}

int getCoins(vector<int> &arr, int k){
    //return the max coins that you can win! 
    int start = 0;
    int end = 0;
    int ans = -1;

    	for (int i = 0; i < arr.size(); i++)
    		end += arr[i]; 

   		while (start <= end){
   			int limit = (start + end) / 2;

   			bool isPossible = divide(arr, k, limit);

   			if (isPossible){
   				ans = limit;
   				start = limit + 1;
   			}

   			else {
   				end = limit - 1;
   			}
   		} 

   	return ans;
}

int32_t main(){
	// write the code here
	vector<int> arr{1, 2, 3, 4};
	int k = 3;

		cout << getCoins(arr, k);

	return 0;
}
