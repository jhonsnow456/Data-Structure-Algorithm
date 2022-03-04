/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

bool checkRedundant(string str){
	stack<char> stk;

		for (char &c: str){
			if (c == ')')
				stk.push(c); // a, b, +, -, (, ...
			else{
				
				// )

				bool operatorFound = false;

				while (!stk.empty() and stk.top() != '('){
					char top = stk.top();

					if (top == '+' or top == '-' or top == '*' or top == '/')
						operatorFound = true;

					stk.pop();
				}

				// pop the opening bracket after
				// the loop if over
				stk.pop(); 

				if (operatorFound == false)
					return true;
			}
		}

	return false;
}

int32_t main(){
	// write the code here
	string expression; cin >> expression;

		cout << (checkRedundant(expression) ? "Redundant expression" : "Not a redundant expression") << endl;

	return 0;
}
