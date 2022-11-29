
//misaka and elaina will carry me to red

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
#include <array>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>
#include <set>
#include <queue>
#include <map>
#include <chrono>
#include <random>

#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define pb push_back
#define eb emplace_back
#define kill(x, s) {if(x){ cout << s << "\n"; return ; }}

#ifndef LOCAL
#define cerr while(0) cerr
#endif

using ll = long long;
using lb = long double;

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = 1e18;
//const ll mod = (1 << (23)) * 119 +1, ll_max = 1e18;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

struct {
  template<class T>
  operator T() {
    T x; std::cin >> x; return x;
  }
} in;

using namespace std;

void solve(){
	cout << 64 << "\n";
	for(int i = 1; i<=8; i++) 
		for(int j = 1; j<=8; j++)
			cout << i << " " << j << "\n";
}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);

  int T = 1;
  //cin >> T;
  for(int i = 1; i<=T; i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
  return 0;
}



