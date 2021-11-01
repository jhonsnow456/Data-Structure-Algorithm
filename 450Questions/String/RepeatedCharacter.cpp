// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/ 

#include <iostream>
#include <unordered_map>

using namespace std;

void printDuplicate(string s){
	unordered_map<char, int> count;
	for (char c: s)
		count[c]++;

	for (auto c: count)
		if (c.second > 1)
			cout << c.first << ":" << c.second << endl;
}

int main(){
	printDuplicate("test string");
	return 0;
}
