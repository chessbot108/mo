
//misaka and elaina will carry me to master
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>

#define lb long double

using namespace std;

const lb eps = 1e-9;
const lb sqrt3 = sqrt(3.0);

lb peano(lb x, lb y, int steps = 0){
	if(steps > 30) return 0.0;
	if(fabs(x) < eps && fabs(y) < eps){
		return 0;
	}
	if(fabs(x - 1.0) < eps && fabs(y - sqrt3) < eps){
		return sqrt(3);
	}	
	if(y < 1.0/sqrt3){
		return peano(y * sqrt3, x * sqrt3, steps+1)/sqrt3;
	}else if(y < 2.0/sqrt(3) ){
		return 1.0/sqrt3 + peano(y * sqrt3 - 1.0, (1.0 - x) * sqrt3, steps+1)/sqrt3;
	}else{
		return 2.0/sqrt3 + peano(y * sqrt3 - 2.0, x * sqrt3, steps+1)/sqrt3;
	}
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int n, D;
	cin >> n >> D;
	vector<pair<lb, int>> order;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		order.push_back(pair(peano(((lb)x/(lb)D) * sqrt3, ((lb)y/(lb)D) * sqrt3), i));
	}
	sort(order.begin(), order.end());
	for(int i = 0; i<n; i++){
		cout << order[i].second << " ";
	}
	cout << "\n";
	return 0;
}

