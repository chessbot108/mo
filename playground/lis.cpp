
//NOT COMPLETE
//DO NOT USE YET


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

using namespace std;

vector<int> lis(vector<pair<int, int>> arr){
	set<int> s;
	for(int i = 0; i<sz(arr); i++){
		auto [y, j] = arr[i];
		s.insert(y);
		auto it = s.upper_bound(y);
		if(it != s.end()){
			s.erase(it);
		}
	}
	vector<int> ans;
	auto it = s.begin();
	for(int x : s) cerr << x << " " ; cerr << "\n";
	for(int i = 0; i<sz(arr); i++){
		cerr << arr[i].first << " " << arr[i].second << " " << *it << "\n";
		if(it != s.end() && *it == arr[i].first){
			ans.push_back(arr[i].second);
			it++;
		}
	}
	//assert(it == s.end());
	return ans;
}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);
	int n, D;
	cin >> n >> D;
	vector<pair<pair<int, int>, int>> vec;
	vector<int> vis(n+1, 0);
	vector<pair<int, int>> points;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair(make_pair(x, y), i));
		points.push_back({x, y});
	}


	vector<int> p;
	while(sz(vec)){
		cerr << "new iteration\n";
		vector<pair<int, int>> up, down;
		sort(all(vec), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
				return a < b;	
				});
		//cerr << "up\n";
		for(int i = 0; i<sz(vec); i++){
			up.push_back(make_pair(vec[i].first.second, vec[i].second));
			//cerr << vec[i].second << " " << vec[i].first.first << " " << vec[i].first.second << "\n";

		}
		sort(all(vec), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
				if(a.first.first != b.first.first){
					return a.first.first > b.first.first;
				}	
				return make_pair(a.first.second, a.second) < make_pair(b.first.second, b.second);
				});
		//cerr << "down\n";
		for(int i = 0; i<sz(vec); i++){
			down.push_back(make_pair(vec[i].first.second, vec[i].second));
			//cerr << vec[i].second << " " << vec[i].first.first << " " << vec[i].first.second << "\n";
		}
		//reverse(all(down));
		auto uplis = lis(up), downlis = lis(down);
		vector<pair<pair<int, int>, int>> newvec;
		if(sz(uplis) > sz(downlis)){
			cerr << "uplis\n";
			for(int x : uplis){
				cerr << "(" << points[x].first << ", " << points[x].second << ") ";				
				vis[x] = 1;
				p.push_back(x);
			}
			cerr << "\n";
			for(int i = 0; i<sz(vec); i++){
				if(!vis[vec[i].second]){
					newvec.push_back(vec[i]);
				}
			}
			for(int x : uplis){
				vis[x] = 0;
			}
			
		}else{
			cerr << "downlis\n";
			for(int x : downlis){
				cerr << "(" << points[x].first << ", " << points[x].second << ") ";
				vis[x] = 1;
				p.push_back(x);
			}
			cerr << "\n";
			for(int i = 0; i<sz(vec); i++){
				if(!vis[vec[i].second]){
					newvec.push_back(vec[i]);
				}
			}
			for(int x : downlis){
				vis[x] = 0;
			}
		}	
		vec = newvec;
	}
	for(int x : p){
		cout << x << " " ;
	} cout << "\n";
	//for(int i = 0; i<sz(p); i++){
		//cerr << points[p[i]].first << " " << points[p[i]].second << "\n";
	//}
	return 0;
}



