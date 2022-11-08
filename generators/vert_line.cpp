

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
	for(int i = 1; i<=N; i++){
		cout << 1 << " " << (((N/D)%2 == 0) ? i : (D + 1 - i)) << "\n";
	}
	return 0;
}
