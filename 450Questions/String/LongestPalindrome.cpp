// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

/*
// brute force: O(N^3) complexity
bool check_palin(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev == s;
}

string longestPalin(string s){ 
    string res;
    int size = s.length();
    int maxlength = 0;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            string substring = s.substr(i, j + 1);
            if (check_palin(substring) and substring.length() > maxlength){
                res = substring;
                maxlength = substring.length();
            }
        }
    }

    return res;
}
*/

string longestPalin(string s){
    int len = s.length();
    string best_string = "";
    int best_length = 0;

        // for even gap in palindrome string 
        for (int mid = 0; mid < len; mid++){
            for (int gap = 0; mid - gap >= 0 and mid + gap < len; gap++){
                if (s[mid - gap] != s[mid + gap]) break;

                int subarray_length = 2 * gap + 1;
                if (subarray_length > best_length){
                    best_length = subarray_length;
                    best_string = s.substr(mid - gap, subarray_length);
                }
            }
        }

        // for odd gap in palindrome string
        for (int mid = 0; mid < len - 1; mid++){
            for (int gap = 1; mid - gap + 1 >= 0 and mid + gap < len; gap++){
                if (s[mid - gap + 1] != s[mid + gap]) break;
                
                int subarray_length = 2 * gap;
                if (subarray_length > best_length){
                    best_length = subarray_length;
                    best_string = s.substr(mid - gap + 1, len);
                }
            }
        }

    return best_string;
}

int main(){
    string S = "vnrtysfrzrmzlygfv";
        cout << longestPalin(S) << endl;        
    return 0;
}