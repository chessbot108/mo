

//this code finds the preorder tour of any minimum manhattan spanning tree and prints it
//it can be proven that any preorders of any manhattan spanning tree will result
//in the same cost. this is because sum of distances traveled by iterating over
//nodes in the order of preorder of a tree is precisely twice the total sum of edges
//as all minimum manhattan spanning trees have the same sum of edges
//any preorder of any manhattan spanning tree is valid
//
//the manhattan spanning tree code is provided by kactl
//i wrote the prims and dfs function
//
//functionality as code which finds the minimum manhattan spanning tree
//is tested on https://judge.yosupo.jp/problem/manhattanmst


#include <iostream>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <array>
#include <numeric>

using namespace std;

template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
const int inf = 1e9; //no edges should have weights that exceed 1 billion

//the code below in the "namespace kactl" is taken from a github repository that contains concise implementations 
//of many algorithms include "minimum manhattan mst which is used here
namespace kactl{
#define rep(i, a, b) for(int i = a; i < (b); ++i)
	typedef long long ll;
	typedef pair<int, int> pii;
	typedef vector<int> vi;

	//SOURCE: kactl
	//https://github.com/kth-competitive-programming/kactl/blob/main/content/geometry/Point.h
	/**
	 * Author: Ulf Lundstrom
	 * Date: 2009-02-26
	 * License: CC0
	 * Source: My head with inspiration from tinyKACTL
	 * Description: Class to handle points in the plane.
	 * 	T can be e.g. double or long long. (Avoid int.)
	 * Status: Works fine, used a lot
	**/
	template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
	template<class T>
		struct Point {
			typedef Point P;
			T x, y;
			explicit Point(T x=0, T y=0) : x(x), y(y) {}
			bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
			bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
			P operator+(P p) const { return P(x+p.x, y+p.y); }
			P operator-(P p) const { return P(x-p.x, y-p.y); }
			P operator*(T d) const { return P(x*d, y*d); }
			P operator/(T d) const { return P(x/d, y/d); }
			T dot(P p) const { return x*p.x + y*p.y; }
			T cross(P p) const { return x*p.y - y*p.x; }
			T cross(P a, P b) const { return (a-*this).cross(b-*this); }
			T dist2() const { return x*x + y*y; }
			double dist() const { return sqrt((double)dist2()); }
			// angle to x-axis in interval [-pi, pi]
			double angle() const { return atan2(y, x); }
			P unit() const { return *this/dist(); } // makes dist()=1
			P perp() const { return P(-y, x); } // rotates +90 degrees
			P normal() const { return perp().unit(); }
			// returns point rotated 'a' radians ccw around the origin
			P rotate(double a) const {
				return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
			friend ostream& operator<<(ostream& os, P p) {
				return os << "(" << p.x << "," << p.y << ")"; }
		};
	/**
	 * Author: chilli, Takanori MAEHARA
	 * Date: 2019-11-02
	 * License: CC0
	 * Source: https://github.com/spaghetti-source/algorithm/blob/master/geometry/rectilinear_mst.cc
	 * Description: Given N points, returns up to 4*N edges, which are guaranteed
	 * to contain a minimum spanning tree for the graph with edge weights w(p, q) =
	 * |p.x - q.x| + |p.y - q.y|. Edges are in the form (distance, src, dst). Use a
	 * standard MST algorithm on the result to find the final MST.
	 * Time: O(N \log N)
	 * Status: Stress-tested
	 **/

	typedef Point<int> P;
	vector<array<int, 3>> manhattanMST(vector<P> ps) {
		vi id(sz(ps));
		iota(all(id), 0);
		vector<array<int, 3>> edges;
		rep(k,0,4) {
			sort(all(id), [&](int i, int j) {
					return (ps[i]-ps[j]).x < (ps[j]-ps[i]).y;});
			map<int, int> sweep;
			for (int i : id) {
				for (auto it = sweep.lower_bound(-ps[i].y);
						it != sweep.end(); sweep.erase(it++)) {
					int j = it->second;
					P d = ps[i] - ps[j];
					if (d.y > d.x) break;
					edges.push_back({d.y + d.x, i, j});
				}
				sweep[-ps[i].y] = i;
			}
			for (P& p : ps) if (k & 1) p.x = -p.x; else swap(p.x, p.y);
		}
		return edges;
	}
#undef rep

}
long long ans = 0;
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
			tr[p].push_back(u);
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

void dfs(int u, vector<vector<int>>& tr, vector<int>& tour, vector<int>& parents){
	tour.push_back(u);
	for(int v : tr[u]){
		parents[v] = u;
		dfs(v, tr, tour, parents);
	}
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int n, D;
	cin >> n >> D;
	vector<kactl::P> points;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		points.push_back(kactl::P(x, y));
	}
	auto edges = kactl::manhattanMST(points);
	auto tr = prim(n, edges);

	vector<int> tour;
	vector<int> parents(n, -1);
	dfs(0, tr, tour, parents);
	for(int i = 0; i<n; i++){
		cout << tour[i] << " ";
	}
	cout << "\n";
	//for(int i = 0; i<n; i++){
		//if(parents[i] != -1){
			//cout << " " << points[parents[i]].x << " " << points[parents[i]].y  << " " << points[i].x << " " << points[i].y << "\n";
		//}
	//}
	cout << "\n";
}


