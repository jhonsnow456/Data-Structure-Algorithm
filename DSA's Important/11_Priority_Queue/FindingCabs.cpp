/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

struct cordinate{
	int x, y;
};

struct compare{
	bool operator()(pair<string, cordinate> a, pair<string, cordinate> b){
		float ea = sqrt(pow(a.second.x, 2) + pow(a.second.y, 2));
		float eb = sqrt(pow(b.second.x, 2) + pow(b.second.y, 2));

		return ea > eb;
	}
};

void solve(){
	// write the code here
	int N, K; cin >> N >> K;
	priority_queue<pair<string, cordinate>, vector<pair<string, cordinate>>, compare> pq;


		for (int i = 0; i < N; i++){
			string s; int x, y;
			cin >> s >> x >> y;

			pq.push({s, {x, y}});
		} 


		while (K--){
			cout << pq.top().first << endl;
			pq.pop();
		}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    // std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			// std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}

