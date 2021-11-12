// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubstring(string s){
    vector<int> arr;
        
        for (char i: s){
            if (i == '0') arr.push_back(-1);
            else if (i == '1') arr.push_back(1);
        }
    
    int cur_sum = 0;
    int counter = 0;
    // int res = 0;

        for (int i = 0; i < arr.size(); i++){
            cur_sum += arr[i];
            // counter++;
                if (cur_sum == 0){
                    // res = max(res, counter);
                    // counter = 0;
                    counter++;
                }            
        }

    return counter;
}

int main(){
    string s = "0100110101";
        cout << maxSubstring(s) << endl;    
    return 0;
}