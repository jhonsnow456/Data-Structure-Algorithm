/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){
	// write the code here
	long long n, x, y;
    cin >> n >> x >> y;
     	
     	x = x + y;
    
    int val = 0;
    int nsum = (n * (n + 1)) / 2;
      
        
        if(nsum % x == 0 ){
            cout<<"POSSIBLE"<<endl;
            x = nsum / x;
            y = y * x;
            nsum = n;
            
            vector<int> res(nsum+3);
            
            for(int i = 1; i <= nsum; i++)
	            if(i >= 1) res[i - 1] = i;
        	
            
            for(int i = nsum-1;i >= 0; i--){
                if(res[i] <= y) 
                	y = y - res[i], res[i]=0;    
            }
          
            for(auto it: res)
                if(it != 0) ++val;
            
            
            cout<<val<<endl;

            for(int i =0; i < nsum; ++i) 
                if(res[i] > 0 or res[i] < 0)    
                    cout << i + 1 << " ";

            cout<<endl;
        }

        else{
            cout<<"IMPOSSIBLE";
            cout << endl;
        }
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int test_case = 1;
    std::cin >> test_case;
 
		for(int i = 1; i <= test_case; i++) {
			std::cout<<"Case #"<< i <<": "; 
			solve();
		}
		
	return 0;
}
