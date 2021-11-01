// https://leetcode.com/problems/reverse-string/submissions/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseString(vector<char>& s){
	reverse(s.begin(), s.end());
}

int main(){
	vector<char> s = {'a', 'b', 'c'};
		reverseString(s);
		
		for (char i: s) cout << i;
		
		cout << endl;
	return 0;
}
