/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.spoj.com/problems/BUSYMAN/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b){
	return a.second < b.second;
}

int countActivites(vector<pair<int,int>>& activities){
    //Complete this method
	sort(activities.begin(), activities.end(), comp);

	int previous = activities[0].second;
	int ans = 1;

		for (int i = 1; i < activities.size(); i++){
			if (activities[i].first >= previous){
				ans++;
				previous = activities[i].second;
			}
		}

	return ans;
}

int32_t main(){
	// write the code here
	vector<pair<int, int>> activities = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}}; 
		cout << countActivites(activities) << endl;
	return 0;
}
