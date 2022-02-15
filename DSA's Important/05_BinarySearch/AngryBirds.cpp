/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://leetcode.com/discuss/general-discussion/1302335/aggressive-cows-spoj-fully-explained-c

#include <bits/stdc++.h>

using namespace std;

bool canBePlaced(int birds, int N, vector<int> nests, int sep){
	int birdCount = 1; // initially palced
	int location = nests[0];

		for (int i = 1; i <= N - 1; i++){
			int currLocation = nests[i];

			if (currLocation - location >= sep){
				birdCount++;
				location = currLocation;

				if (birdCount == birds)
					return true;
			}
		}

	return false;
}

int angryBirds(vector<int> nests, int birds){
	int N = nests.size();
	int start = 0, end = nests[N - 1] - nests[0];
	int ans = -1;

		while (start <= end){
			int mid = (start + end) / 2;

			bool canPlaced = canBePlaced(birds, N, nests, mid);

			if (canPlaced){
				ans = mid;
				start = mid + 1;
			}else{
				end = mid - 1;
			}
		}

	return ans;
}

int32_t main(){
	// write the code here
	vector<int> nests = {1, 2, 4, 8, 9};
	int birds = 3;

		cout << angryBirds(nests, birds) << endl;

	return 0;
} 
