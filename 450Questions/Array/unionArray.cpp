// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int doUnion(int a[], int m, int b[], int n){
    set<int> s;

    for (int i = 0; i < m; i++)
        s.insert(a[i]);
    for (int j = 0; j < n; j++)
        s.insert(b[j]);

    return s.size();
}

int main(){
    int m = 5, n = 3;
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3};

    cout << doUnion(a, m, b, n) << endl;
    return 0;
}