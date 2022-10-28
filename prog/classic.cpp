
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
	int B = N/sqrt(D);
	vector<pair<int, int>> points(N);
	for(int i = 0; i<N; i++){
		cin >> points[i].first >> points[i].second;
	}
	vector<int> p(N);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int a, int b){
		if(points[a].first/B != points[b].first/B){
			return points[a].first < points[b].first;
		}
		return points[a].second < points[b].second;
	});
	for(int x : p){
		cout << x << " ";
	}
	cout << "\n";
}
