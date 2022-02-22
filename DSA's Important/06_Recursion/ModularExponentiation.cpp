/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

long long int powerModulo(int a, int b){
    //Write your code here. Do not modify the function or parameters.
	if (a == 0)
		return 0;
	else if (b == 0) 
		return 1;

	long long int y;

	// power is odd
	if (b % 2)
		return 	(a * powerModulo(a, b - 1) % mod) % mod;
	else{
		y = powerModulo(a, b / 2);
		return (y * y) % mod;
	}

	return (y + mod) % mod;
}

int32_t main(){
	// write the code here
	int a, b; cin >> a >> b;

		cout << powerModulo(a, b) << endl;

	return 0;
}
