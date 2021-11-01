// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/


#include <iostream>
#include <queue>

using namespace std;

bool checkrotation(string s1, string s2){
	if (s1.length() != s2.length()) return false;

    queue<char> q1, q2;

    for (char i: s1) q1.push(i);
    for (char i: s2) q2.push(i);

    int k = s2.length();

    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        
		if (q2 == q1) return true;
    }

    return false;
}

int main(){
	cout << checkrotation("ACBD", "CDAB") << endl;
	return 0;
}
