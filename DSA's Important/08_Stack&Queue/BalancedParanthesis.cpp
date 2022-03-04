/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string s){
	stack<char> stk;
		for (char &c: s){
			
			if (c == '[' or c == '(' or c == '{'){
				stk.push(c);
				continue;
			}

			if (stk.empty())
				return false;

			char x;

			switch(c){
				case ')':
					x = stk.top();
					stk.pop();
					if (x == '{' or x == '[')
						return false;
					break;

				case '}':
					x = stk.top();
					stk.pop();
					if (x == '(' or x == '[')
						return false;
					break;
				
				case ']':
					x = stk.top();
					stk.pop();
					if (x == '(' or x == '{')
						return false;
					break;
			}
		}
	return stk.empty();
}

int32_t main(){
	// write the code here
	string expression = "[A + (B + C)]";

		cout << (isBalanced(expression) ? "Balanced Expression" : "Not a Balanced expression") << endl;

	return 0;
}
