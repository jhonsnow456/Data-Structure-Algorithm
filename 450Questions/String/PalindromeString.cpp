// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1# 

#include <iostream>
#include <algorithm>

using namespace std;

int isPalindrome(string s){
	string reverseString = s;
	reverse(reverseString.begin(), reverseString.end());
	return reverseString == s;
}

int main(){
	cout << isPalindrome("abc") << endl;
	return 0;
}
