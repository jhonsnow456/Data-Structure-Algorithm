/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

/*
Replace the space in the string in "%20" charcters
for example, 
Input:  I love India.
Output: I%20love%20India.
*/

#include <bits/stdc++.h>

using namespace std;

void space20(char* sentence){
	int spaces = 0;

		for (int i = 0; i < strlen(sentence); i++)
			if (sentence[i] == ' ') spaces++;

	int indx = strlen(sentence) + 2 * spaces;
	sentence[indx] = '\0';

		for (int i = strlen(sentence) - 1; i >= 0; i--){
			if (sentence[i] == ' '){ 
				sentence[indx - 1] = '0';
				sentence[indx - 2] = '2';
				sentence[indx - 3] = '%';

				indx -= 3;
			}
			else {
				sentence[indx - 1] = sentence[i];
				indx--;
			}
		}
}

int32_t main(){
	// write the code here
	char input[100];
	cin.getline(input, 1000);

		space20(input);
		cout << input << endl;
	
	return 0;
}
