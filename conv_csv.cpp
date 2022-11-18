#include <iostream>
#include <fstream>
using namespace std;

const int MX = 1e3;

char str[MX], fi[MX];

int main(int argc, char* agrv[]){
	cin.tie(0) -> sync_with_stdio(0);
	str = argv[1];
	int dmax = atoi(argv[2]);
	int dinc = atoi(argv[3]);
	int nmax = atoi(argv[4]);
	int ninc = atoi(argv[5]);
	fstream fout(string(str, str + strlen(str)) + ".txt");
	for(int d = dinc; d<=dmax; d+=dinc){
		for(int n = ninc; n<=nmax; n+=ninc){
			memset(fi, 0, sizeof(fi));
			sprintf(fi, "./test_%d_%d/%s.txt", n, d, str);
			fstream fin(string(fi, fi + strlen(fi)));
			int val = -1;
			fin >> val;
			if(val < 0) cerr << "we have an issue here. line "<<  __LINE__  << " while handling " << string(str, str + strlen(str));
			fout << val << ",";
		}
		fout << "\n";
	}

	return 0;
}
