/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://www.geeksforgeeks.org/sparse-search/

#include <bits/stdc++.h>

using namespace std;

int sparseSearch(vector<string> s, string key){
	int start = 0;
	int end = s.size() - 1;

		while (start <= end){

			int mid = (start + end) / 2;
			int left_mid = mid - 1;
			int right_mid = mid + 1;

				// check for the blank string 
				if (s[mid] == ""){

					while (true){
						if (left_mid < start and right_mid > end)
							return -1;
						else if (right_mid <= end and s[right_mid] != ""){
							mid = right_mid;
							break;
						}
						else if (left_mid >= start and s[left_mid] != ""){
							mid = left_mid;
							break;
						}

						left_mid++;
						right_mid--;
					}
				}

				// check if the key == mid
				if (s[mid] == key)
					return mid;

				// check if key > mid
				else if (s[mid] > key)
					end = mid - 1;

				// check if key < mid
				else
					start = mid + 1;
		}

	return -1;
}

int32_t main(){
	// write the code here
	vector<string> s =  {"ai", "", "","bat", "","","car","cat","","","dog",""};
	string k = "bat";

		cout << sparseSearch(s, k);

	return 0;
}
