
#include <iostream>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>

#define lb long double
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()

const lb epsilon = 1e-6;

using namespace std;


//https://rangevoting.org/SpaceFillCurve.html
lb sierpinski(lb x, lb y){
	lb t = 0, u = 1;
	lb delta = epsilon*epsilon/8.0;
	if(x > y){
		t = t + delta;
		x = 1.0 - x;
		y = 1.0 - y;
	}
	while(u > epsilon){
		t = 2.0*t;
		if(x + y > 1){
			t = t + delta;
			y = 1.0 - y;
			swap(x, y);
		}
		x = 2.0*x;
		y = 2.0*y;
		t = 2.0*t;
		if(y > 1){
			t = t + delta;
			x = 1.0 - x;
			y = y - 1.0;
			swap(x, y);
		}
		u = u/2.0;
	}
	return t;
}


signed main(){
  cin.tie(0) -> sync_with_stdio(0);
int n, D;
D = 16;
n = D*D;
	//cin >> n >> D;
	vector<pair<lb, int>> order;
	for(int i = 0; i<n; i++){
		int x, y;
		x = i/16, y = i%16;
		order.push_back(pair(sierpinski((lb)(x)/(lb)D, (lb)(y)/(lb)D), i));
	}
	sort(all(order));
	for(int i = 0; i<n; i++){
		cout << order[i].second << " ";
	}
	cout << "\n";
  return 0;
}



