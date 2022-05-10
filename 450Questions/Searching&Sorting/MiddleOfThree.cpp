/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/middle-of-three2926/1

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int middle(int A, int B, int C){
	vector<int> arr(3);
        
	    arr[0] = A, arr[1] = B, arr[2] = C;
	    sort(arr.begin(), arr.end());
	    
	return arr[1];
}

void solve(){
	// write the code here
	int a, b, c; cin >> a >> b >> c;
	cout << middle(a, b, c) << endl;
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
