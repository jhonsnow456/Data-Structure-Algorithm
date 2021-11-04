// https://leetcode.com/problems/count-and-say/

#include <iostream>

using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";
    if (n == 2) return "11";
    
    string baseString = "11";

    for (int i = 3; i <= n; i++){
        string sayString = "";
        baseString += '\0';
        
        int count = 1;
        for (int j = 1; j < baseString.length(); j++){
            if (baseString[j] != baseString[j - 1]){
                sayString += to_string(count);
                sayString += baseString[j - 1];
                count = 1;
            }else count++;
        }

        baseString = sayString;
    }

    return baseString;
}

int main(){
        cout << countAndSay(4) << endl;
    return 0;
}