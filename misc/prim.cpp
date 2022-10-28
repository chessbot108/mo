
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
#include <array>
#include <queue>
#include <map>
#include <chrono>
#include <random>

#define ll long long
#define lb long double
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define kill(x, s) {if(x){ cout << s << "\n"; return ; }}

#ifndef LOCAL
#define cerr while(0) cerr
#endif

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
template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

ll ans = 0;
const int inf = 1e9 +10;
vector<vector<int>> prim(int n, vector<array<int, 3>> edges){
	min_pq<array<int, 3>> pq;
	vector<int> dist(n, inf), vis(n, 0);
	vector<vector<int>> tr(n);
	vector<vector<pair<int, int>>> adj(n);
	for(auto [w, u, v] : edges){
		adj[u].push_back(pair(v, w));
		adj[v].push_back(pair(u, w));
	}
	dist[0] = 0;
	pq.push({0, 0, -1});
	while(!pq.empty()){
		auto [d, u, p] = pq.top(); pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		ans += dist[u];
		if(p != -1){
			tr[p].pb(u);
		}
		for(auto [v, w] : adj[u]){
			if(dist[v] > w){
				dist[v] = w;
				pq.push({dist[v], v, u});
			}
		}
	}
	return tr;
}
void solve(){
	int n, m;
	n = in, m = in;
	vector<array<int, 3>> edges;
	for(int i = 0;i <m; i++){
		int a = in, b = in, c = in;
		a--, b--;
		edges.pb({c, a, b});
	}
	auto tr = prim(n, edges);
	cout << ans << "\n";

}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);

  int T = 1;
  //cin >> T;
  for(int i = 1; i<=T; i++){
		solve();
	}
  return 0;
}



