// https://practice.geeksforgeeks.org/problems/edit-distance3702/1#

#include <iostream>

using namespace std;

// Approch 1 using recursion 
int minCost(int x, int y, int z){
    return min(min(x, y), z);
}

int editDistance(string s, string t){
    int n = s.length();
    int m = t.length();
    
    if (n == 0) return m;
    if (m == 0) return n;

    // if both the strings are same 
    if (s[n - 1] == t[m - 1]) return editDistance(s.substr(0, n-1), t.substr(0, m-1)); 

    return 1 + minCost(
        editDistance(s.substr(0, n-1), t.substr(0, m)), // removing the character
        editDistance(s.substr(0, n), t.substr(0, m-1)), // adding the character
        editDistance(s.substr(0, n-1), s.substr(0, m-1)) // transtioning the character
        );
}

int main(){
    string s1 = "geek", s2 = "geesk";
        cout << editDistance(s1, s2) << endl; 
    return 0;
}