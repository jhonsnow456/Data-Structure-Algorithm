// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> resultantPermutation;

void permute(string str, int left_pointer, int right_pointer){
    if (left_pointer == right_pointer) resultantPermutation.push_back(str);
    
    for (int i = left_pointer; i <= right_pointer; i++){
        // swapping the piositin to create permutation
        swap(str[left_pointer], str[i]);

        permute(str, left_pointer + 1, right_pointer);
        
        // reversing back to original string
        swap(str[left_pointer], str[i]);
    }
}

vector<string> find_permutation(string s){
    permute(s, 0, s.length()-1);  
    sort(resultantPermutation.begin(), resultantPermutation.end());
    return resultantPermutation;    
}

int main(){
    string s = "ljr";
        
        for (string permutedString: find_permutation(s))
            cout << permutedString << endl;

    return 0;
}