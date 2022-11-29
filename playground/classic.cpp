
#include <iostream> //input
#include <vector> //vector
#include <algorithm> //sort
#include <utility> //pairs
#include <numeric> //iota
using namespace std;


//const int B = 300;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int N, D;
	cin >> N >> D;
	int B = 3;
	vector<pair<int, int>> points(N);
	for(int i = 0; i<N; i++){
		cin >> points[i].first >> points[i].second;
	}
	vector<int> p(N);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int a, int b){
		if((points[a].first-1)/B != (points[b].first-1)/B){
			return points[a].first < points[b].first;
		}
		return points[a].second < points[b].second || (points[a].second == points[b].second && points[a].first < points[b].first);
	});
	for(int x : p){
		cout << x << " ";
	}
	cout << "\n";
}
