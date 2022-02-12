/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

float squareRoot(int N, int P){
	int start = 0;
	int end = N;
	float ans = 0;

		// perform binary search (0...N)
		while (start <= end){
			int mid = (start + end) / 2;

			if (mid * mid == N)
				return mid;

			else if (mid * mid < N){
				ans = mid;
				start = mid + 1;
			}

			else
				end = mid - 1;
		}

	float inc = 0.1;

		// perform linear search (for floating part)
		while (P--){
			
			while (ans * ans < N)
				ans += inc;

			ans -= inc;
			inc = inc / 10.0;
		}

	return ans;
}

int32_t main(){
	// write the code here
	int n, p; cin >> n >> p;
		
		cout << squareRoot(n, p) << endl;

	return 0;
}
