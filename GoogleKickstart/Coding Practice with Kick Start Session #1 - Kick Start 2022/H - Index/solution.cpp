/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

// core : largest integer H such that the researcher has H papers 
// 		  with at least H citations each. 

void HIndexScore(vector<int> citations){
	int N = citations.size(), h = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

		for (int &citation: citations){
			if (citation > h){
				pq.push(citation);

				while (pq.top() > h && pq.size() > h)
					h++;
			}

			cout << h << " ";

			while (pq.top() <= h && !pq.empty())
				pq.pop();
		}		

	cout << endl;
}

void solve(){
	// write the code here
	int N; cin >> N;
	vector<int> citations(N);

		for (int &citation: citations) cin >> citation;

		HIndexScore(citations);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}

