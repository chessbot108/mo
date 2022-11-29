//enumerate all numbers x * 2^k, x * 2^k +1



#include <iostream>
#include <random>
using namespace std;


int main(int argc, char *argv[]){
	cin.tie(0) -> sync_with_stdio(0);
	int N = atoi(argv[1]);
	int D = atoi(argv[2]);
	mt19937 rng(atoi(argv[3]));
	uniform_int_distribution<int> distr(1, D);
	cout << N << " " << D << "\n";
	int k = 0;
	while((1 << k) * (1 << k) < N*4 && (1 << k) < D){
		k++;
	}
	vector<int> relevant;
	for(int i = 1; i<=D; i++){
		if(i%(1 << k) == 1 || i%(1 << k) == 0){
			relevant.push_back(i);
		}
	}
	int oup = 0;
	for(int x : relevant){
		for(int y : relevant){
			if(oup < N){
				cout << x << " " << y << "\n";
				oup++;
			}
		}
	}
	while(oup < N){
		cout << distr(rng) << " " << distr(rng) << "\n";
		oup++;
	}
	return 0;
}
