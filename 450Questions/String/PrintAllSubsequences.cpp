// https://www.geeksforgeeks.org/print-subsequences-string/

#include <iostream>
#include <unordered_set>

using namespace std;


// TIME COMPLEXITY: O(2^N)
unordered_set<string> res;

void generateSubsequence(string input, string output){
    if (input.empty()){
        res.insert(output);
        return;
    }
    generateSubsequence(input.substr(1), output);
    generateSubsequence(input.substr(1), output + input[0]);
}

void printSubsequences(string s){
    generateSubsequence(s, "");
    for (auto i: res)
        cout << i << " ";
    cout << endl;             
}


int main(){
    string s = "aabc";
        printSubsequences(s);
    return 0;
}