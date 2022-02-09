/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    int n = teams.size();
    vector<int> cnt(n + 1, 0);

    	for (int i = 0; i < n; i++)
    		cnt[teams[i].second]++;

    int sum = 0, pos = 1;

    	for (int i = 1; i <= n; i++)
    		while (cnt[i]){
    			sum += abs(pos - i);
    			cnt[i]--;
    			pos++;
    		}
 
	return sum;
}

int32_t main(){
	// write the code here
	vector<pair<string, int>> teams;
	string str; int num;

		while (cin >> str >> num)
			teams.push_back({str, num});

		cout << badness(teams) << endl;

	return 0;
}
