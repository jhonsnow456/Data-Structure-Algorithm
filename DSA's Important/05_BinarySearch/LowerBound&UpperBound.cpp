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
	int ans = -1;

		while (start <= end){
			int mid = (start + end) / 2;

			if (v[mid] > key){
				end = mid - 1;
			}else{
				ans = mid;
				start = mid + 1;
			}
		}

	return ans;
}

int32_t main(){
	// write the code here
	vector<int> v = {0, 1, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 16};
	
		cout << lower_bound(v, 3) << endl;
		cout << upper_bound(v, 3) << endl;

	return 0;
}
