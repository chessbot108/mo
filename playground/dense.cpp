

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
	int k = sqrt(N);
	int cnt = 0;
	for(int i = 1; i<=k; i++){
		for(int j = 1; j<=k; j++){
			cout << i << " " << j << "\n";
			cnt++;
		}
	}
	while(cnt < N){
		cout << k << " " << k << "\n";
		cnt++;
	}

	return 0;
}
