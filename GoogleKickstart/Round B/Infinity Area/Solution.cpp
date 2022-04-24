/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	int r, a, b;
	cin >> r >> a >> b;

	double area = M_PI * r * r;
	int i = 0;
		
		do{
			r = (i % 2 == 0) ? (r * a) : (r / b);
			area += M_PI * r * r;
			i++;
		}while(r);

	cout << fixed << setprecision(6) << area << endl;
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

