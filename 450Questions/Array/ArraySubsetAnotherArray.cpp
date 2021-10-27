// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#

#include <iostream>
#include <unordered_set>

using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_set<int> s;
    
    for (int i = 0; i < n; i++)
        s.insert(a1[i]);
    
    int count = 0;
    
    for (int i = 0; i < m; i++)
        if (s.find(a2[i]) != s.end())
            count++;
    
    return (count == m) ? "Yes":"No";;
}

int main(){
    int a1[] = {1, 2, 3, 4, 5, 6};
    int a2[] = {1, 2, 4};

        cout << isSubset(a1, a2, 6, 3) << endl;

    return 0;
}