

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
	while(N > 0){
		for(int i = 1; i<=D && N > 0; i++){
			cout << 1 << " " << i << "\n";
			N--;
		}
		for(int i = 1; i<=D && N > 0; i++){
			cout << i << " " << D << "\n";
			N--;
		}
		for(int i = D; i>=1 && N>0; i++){
			cout << D << " " << i << "\n";
			N--;
		}
		for(int i = D; i>=1 && N>0; i++){
			cout << i << " " << 1 << "\n";
			N--;
		}	
		
	}
	return 0;
}
