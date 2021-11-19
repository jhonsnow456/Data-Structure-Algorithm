// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include <iostream>
#include <stack>

using namespace std;

bool isParenthesis(string s){
    stack<char> stk;

    if (s[0] == ')' or s[0] == '}' or s[0] == ']') return false;

    for (char i: s){
        if (i == '{' or i == '(' or i == '[')
            stk.push(i);
        
        else if (!stk.empty() and i == '}'){
            if (stk.top() == '{')
                stk.pop();
            else {
                return false;
            }
        }

        else if (!stk.empty() and i == ')'){
            if (stk.top() == '(')
                stk.pop();
            else {
                return false;
            }
        }

        else if (!stk.empty() and i == ']'){
            if (stk.top() == '[')
                stk.pop();
            else {
                return false;
            }
        }
    }
    
    if (!stk.empty()) return false;
    return true;
}

int main(){
    string s = "{(})";
        cout << isParenthesis(s) << endl;
    return 0;
}