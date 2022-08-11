/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

struct Point{
    int x; 
    int y;
};

int countRightAngledTriangle(vector<Point> &points){
    unordered_map<int, int> fx, fy;

        for (auto &point: points){
            fx[point.x]++;
            fy[point.y]++;
        }

    int cnt = 0;

        for (auto &point: points)
            cnt += (fx[point.x] - 1)*(fy[point.y] - 1);

    return cnt;
}

void solve(){
    // write the code here
    int n; cin >> n;
    vector<Point> points(n);

        for (auto &i: points)
            cin >> i.x >> i.y;


    cout << countRightAngledTriangle(points) << endl;
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
