/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

#include <bits/stdc++.h>

using namespace std;

#define int long long int

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

void insertHeap(int &x){
    if (max_heap.empty() or max_heap.top() > x)
        max_heap.push(x);
    else 
        min_heap.push(x);
        
        
    if (max_heap.size() > min_heap.size() + 1){
        min_heap.push(max_heap.top());
        max_heap.pop();
    }else if (max_heap.size() + 1 < min_heap.size()){
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

double getMedian(){
    if (max_heap.size() == min_heap.size()){
        if (max_heap.empty()) return 0;
        else return (min_heap.top() + max_heap.top()) / 2.0;
    }else{
        if (max_heap.size() > min_heap.size()) return max_heap.top();
        else return min_heap.top();
    }
}

void solve(){
	// write the code here
	int k;

		while (cin >> k){
			insertHeap(k);
			cout << getMedian() << ", ";
		}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    // std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			// std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}
