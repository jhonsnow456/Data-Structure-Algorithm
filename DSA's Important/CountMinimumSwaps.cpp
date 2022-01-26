/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/minimum-swaps/1

#include <bits/stdc++.h>

using namespace std;

int countMinSwaps(vector<int> arr){
	// arr = 5, 4, 3, 2, 1
	int n = arr.size(); int minSwaps = 0;
	pair<int, int> ap[n];

		
		for (int i = 0; i < n; i++)
			ap[i] = {arr[i], i};
		//  ap = {{5, 0}, {4, 1}, {3, 2}, {2, 3}, {1, 4}}

		// ap = {{1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0}}
		sort(ap, ap + n);

	vector<bool> visited(n, false);

		for (int i = 0; i < n ; i++){
			int old_index = ap[i].second;

			// if the element is visited or at the right position
			if (visited[i] == true or i == old_index)
				continue;

			// else visiting the element for the first time
			int node = i;
			int cycle = 0;

			while (!visited[node]){
				visited[node] = true;
				int next_node = ap[node].second;
				node = next_node;
				cycle++;
			}

			minSwaps += (cycle - 1);
		}


	return minSwaps;
}

int32_t main(){
	// write the code here
	vector<int> arr = {5, 4, 3, 2, 1};

		cout << countMinSwaps(arr) << endl;

	return 0;
}
