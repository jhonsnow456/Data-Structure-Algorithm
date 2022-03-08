/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> &arr){
    for (int &val: arr)
        cout << val << " ";
}

void MaxSubArray(vector<int> arr, int k){
    deque<int> dq(k); // stores the index of the max in the range

    int idx = 0; 
    vector<int> res;

        // TODO 1: Process only the first k element
        for (idx = 0; idx < k; idx++){
            while (!dq.empty() and arr[idx] > arr[dq.back()])
                dq.pop_back();
            dq.push_back(idx);
        }

        // TODO 2: Process the remaining element of the array
        for (; idx < arr.size(); idx++){
            res.push_back(arr[dq.front()]);

            while (!dq.empty() and dq.front() <= idx - k)
                dq.pop_front();

            while (!dq.empty() and arr[idx] >= arr[dq.back()])
                dq.pop_back();

            dq.push_back(idx);
        } 

        res.push_back(dq.front());

    displayArray(res);
}


int32_t main(){
	// write the code here
    vector<int> a{1,2,3,1,4,5,2,3,5};

        MaxSubArray(a, 3);

	return 0;
}
