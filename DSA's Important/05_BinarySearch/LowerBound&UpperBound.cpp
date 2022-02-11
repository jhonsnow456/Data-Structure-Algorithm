/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

int lower_bound(vector<int> &v, int key){
	int start = 0;
	int end = v.size() - 1;
	int ans = -1;

		while (start <= end){
			int mid = (start + end) / 2;

			if (v[mid] >= key){
				ans = mid;
				end = mid - 1;
			}else{
				start = mid + 1;
			}
		}

	return ans;
}

int upper_bound(vector<int> &v, int key){
	int start = 0;
	int end = v.size() - 1;
	int ans = 0;

		while (start <= end){
			int mid = (start + end) / 2;

			if (v[mid] > key){
				end = mid - 1;
			}else{
				ans = mid + 1;
				start = mid + 1;
			}
		}

	return ans;
}

int32_t main(){
	// write the code here
	vector<int> v = {0, 1, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 16};
	
		// DEFINED BY ME
		cout << "LOWER BOUND DEFINED by ME: " << lower_bound(v, -1) << endl;
		cout << "UPPER BOUND DEFINED by ME: " << upper_bound(v, -1) << endl;
		cout << "DIFFERENCE: " << upper_bound(v, -1) - lower_bound(v, -1) << endl;

		// DEFINED BY STL
		cout << "LOWER BOUND in STL: " << lower_bound(v.begin(), v.end(), -1) - v.begin() << endl;
		cout << "UPPER BOUND in STL: " << upper_bound(v.begin(), v.end(), -1) - v.begin() << endl;
		cout << "DIFFERENCE: " << upper_bound(v.begin(), v.end(), -1) - lower_bound(v.begin(), v.end(), -1) << endl;
	
	return 0;
}
