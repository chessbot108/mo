

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

const int MX = 1e3;

char str[MX], fi[MX];

int main(int argc, char * argv[]){
    cin.tie(0) -> sync_with_stdio(0);
        int len = strlen(argv[1]);
        for(int i = 0; i<len; i++){
            str[i] = argv[1][i];
        }
    int dmax = atoi(argv[2]);
    int dinc = atoi(argv[3]);
    int nmax = atoi(argv[4]);
    int ninc = atoi(argv[5]);
    fstream fout(string(str, str+strlen(str)) + ".txt");

    for(int n = ninc; n<=nmax; n+=ninc){
        for(int d = dinc; d<=dmax; d+=dinc){
            memset(fi, 0, sizeof(fi));
            sprintf(fi, "./test_%d_%d/%s.txt", n, d, str);
            fstream fin(string(fi, fi+strlen(fi)));
            int val = 0;
            fin >> val;
            fout << val << ",";
        }
    }        
    fout << "\n";

    return 0;
}
