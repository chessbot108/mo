

#include <iostream>
#include <random>
#include <cmath>
using namespace std;


int main(int argc, char *argv[]){
	cin.tie(0) -> sync_with_stdio(0);
	int N = atoi(argv[1]);
	int D = atoi(argv[2]);
	mt19937 rng(atoi(argv[3]));
	uniform_int_distribution<int> distr(1, D);
	cout << N << " " << D << "\n";
	int count_per_row = sqrt(N)*2;
	int space = D/count_per_row;
	int oup = 0;
	for(int i = 1; i<= count_per_row; i++){
		for(int j = 1; j<=count_per_row; j++){
			if((i + j)%2 == 0){
				oup++;
				cout << i*space << " " << j*space << "\n";
			}
		}
	}
	while(oup < N){
		cout << distr(rng) << " " << distr(rng) << "\n";
		oup++;
	}
	return 0;
}
