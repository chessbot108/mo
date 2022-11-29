

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi2,popcnt,lzcnt")
//misaka will carry me to master
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <set>
#include <map>

#define ll long long
#define lb long double
#define sz(vec) ((int)(vec.size()))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

const lb epsilon = 1e-9;
const ll mod = 1e9 + 7, ll_max = 1e18;
//const ll mod = (1 << (23)) * 119 +1;
const int MX = 5e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
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

int cnt[MX];
const int magic = 700;

int good[MX/magic];

int arr[MX], ans[MX];
int n, m;

int bl(int x){
	return x/magic;
}

void add(int x){
	x = arr[x];
	cnt[x]++;
	if(cnt[x] == 1){
		good[bl(x)]++;
	}
	if(cnt[x] == 2){
		good[bl(x)]--;
	}
}

void del(int x){
	x = arr[x];
	cnt[x]--;
	//assert(cnt[x] >= 0);
	if(cnt[x] == 1){
		good[bl(x)]++;
	}
	if(cnt[x] == 0){
		good[bl(x)]--;
	}
}

int gans(){
	for(int i = 0; i<=n/magic; i++){
		if(good[i]){
			for(int j = i*magic; j<(i+1)*magic; j++){
				if(cnt[j] == 1) return j;
			}
		}
	}
	return 0;
}

struct qq{
	int l, r;
	int ind;
	lb ord;

	qq(int a, int b, int c, int n){
		l = a, r = b, ind = c;
		ord = sierpinski((lb)(a-1)/(lb)n, (lb)(b-1)/(lb)(n));
	}
	bool operator < (const qq& b) const{
		return ord < b.ord;
	}
};

vector<qq> query;

void mo(){
	sort(all(query));
	int cur_l = 0;
	int cur_r = -1;
	// invariant: data structure will always reflect the range [cur_l, cur_r]
	for (const qq& q : query) {
		while (cur_l > q.l) {
			cur_l--;
			add(cur_l);
		}
		while (cur_r < q.r) {
			cur_r++;
			add(cur_r);
		}
		while (cur_l < q.l) {
			del(cur_l);
			cur_l++;
		}
		while (cur_r > q.r) {
			del(cur_r);
			cur_r--;
		}
		ans[q.ind] = gans();
	}
}


void solve(){
	cin >> n;
	for(int i =1; i<=n; i++){
		cin >> arr[i];
	}
	cin >> m;
	for(int i = 1; i<=m; i++){
		int a, b;
		cin >> a >> b;
		query.pb(qq(a, b, i, n));
	}
	mo();
	for(int i = 1; i<=m; i++){
		cout << ans[i] << "\n";
	}
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);

	int T = 1;
	//cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
