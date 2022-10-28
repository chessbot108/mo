
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

vector<pair<int, int>> lis(vector<pair<int, int>> arr){
	set<pair<pair<int, int>, int>> s;
	for(int i = 0; i<sz(arr); i++){
		auto [y, j] = arr[i];
		auto tmp = make_pair(make_pair(y, i), j);
		s.insert(tmp);
		auto it = s.upper_bound(tmp);
		if(it != s.end()){
			s.erase(it);
		}
	}
	vector<pair<int, int>> ans;
	for(auto [y, i, j] : s){
		ans.pb(
	}
}

signed main(){
  cin.tie(0) -> sync_with_stdio(0);
	int n, D;
	cin >> n >> D;
	vector<pair<pair<int, int>, int>> vec;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair(make_pair(x, y), i));
	}


	vector<int> p;
	while(sz(vec)){
		vector<pair<int, int>> up, down;
		sort(all(vec), [&](pair<int, pair<int, int>, int> a, pair<pair<int, int>, int> b){
				return a < b;	
				});
		for(int i = 0; i<sz(vec); i++){
			up.push_back(make_pair(vec[i].first.second, vec[i].second));
		}
		sort(all(vec), [&](pair<int, pair<int, int>, int> a, pair<pair<int, int>, int> b){
				if(a.first.first != b.first.first){
					return a.first.first > b.first.first;
				}	
				return make_pair(a.first.second, a.second) < make_pair(b.first.second, b.second);
				});
		for(int i = 0; i<sz(vec); i++){
			down.push_back(make_pair(vec[i].first.second, vec[i].second));
		}

	}
	return 0;
}



