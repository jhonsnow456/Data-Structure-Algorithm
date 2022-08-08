/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

struct Point{
	int x, y;

	Point(){}

	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

struct comp{
	bool operator()(const Point p1, const Point p2) const{
		if (p1.x == p2.x) return p1.y < p2.y;
		return p1.x < p2.x;
	}
};

int count_rectangles(vector<Point> points){
	int ans = 0;
	set<Point, comp> s;

		for (Point point: points)
			s.insert(point);

		for (auto it = points.begin(); it != prev(points.end()); it++){
			for (auto jt = next(it); jt != points.end(); jt++){
				Point p1 = *it;
				Point p2 = *jt;

				if (p1.x == p2.x or p1.y == p2.y)
					continue;

				Point p3(p1.x, p2.y);
				Point p4(p2.x, p1.y);

				if (s.count(p3) > 0 and s.count(p4) > 0)
					ans++;
			}
		}

	return ans / 2;
}

void solve(){
	// write the code here
	int n; cin >> n;
	vector<Point> points;

		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			points.push_back({x, y});
		}

	cout << count_rectangles(points) << endl;
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
