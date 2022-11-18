
//misaka and elaina will carry me to master
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;


//https://codeforces.com/blog/entry/61203
inline int64_t hilbertOrder(int x, int y, int pow = 21, int rotate = 0) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}



int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int n, D;
	cin >> n >> D;
	vector<pair<int64_t, int>> order;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		order.push_back(pair(hilbertOrder(x-1, y-1), i));
	}
	sort(order.begin(), order.end());
	for(int i = 0; i<n; i++){
		cout << order[i].second << " ";
	}
	cout << "\n";

	return 0;
}
