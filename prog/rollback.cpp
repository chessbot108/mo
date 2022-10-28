
//misaka and elaina will carry me to master
#include <iostream>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

const int magic = 300;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int n, D;
	cin >> n >> D;
	vector<pair<int, int>> points;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int a, int b){
		int lena = points[a].second - points[a].first, lenb = points[b].second - points[b].first;
		if((abs(lena) <= magic) ^ (abs(lenb) <= magic)){
			return abs(lena) <= magic;
		}else{
			if(points[a].first/magic != points[b].first/magic) return points[a].first < points[b].first;
			return points[a].second < points[b].second;
		}
	});
	for(int i = 0; i<n; i++){
		cout << p[i] << " ";
	}
	cout << "\n";
	return 0;
}
