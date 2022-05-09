// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#

#include<bits/stdc++.h>

using namespace std;

vector<int> find(int arr[], int n , int x ){
    
    int firstOccurance = n, lastOccurance = -1;
    
        for (int i = 0; i < n; i++){
            if (arr[i] == x){
                lastOccurance = max(lastOccurance, i);
            }
        }
        
        for (int i = n - 1; i >= 0; i--){
            if (arr[i] == x){
                firstOccurance = min(firstOccurance, i);
            }
        }
    
    firstOccurance =  (firstOccurance == n) ? -1 : firstOccurance;
    
    return {firstOccurance, lastOccurance};
}

vector<int> find(int arr[], int n , int x ){
    
    int firstOccurance = lower_bound(arr, arr + n, x) - arr;
    int lastOccurance = upper_bound(arr, arr + n, x) - arr;
    
    if (firstOccurance == lastOccurance) return {-1, -1}; 
    else return {firstOccurance, lastOccurance};
}

int main(){
    int test_case;
    cin >> test_case;

        while(test_case--){
            int n,x; cin >> n >> x;
            int arr[n],i;

                for(i=0;i<n;i++) cin>>arr[i];
            
            vector<int> ans;
            
                ans = find(arr,n,x);
            
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }

    return 0;
}
