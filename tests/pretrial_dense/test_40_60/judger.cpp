
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){
	cin.tie(0) -> sync_with_stdio(0);
		
	int test_count = atoi(argv[2]);
	
	cerr << "test count is " << test_count << " and file is " << string(argv[1]) << "\n";

	long long worst_case = 0, avg_case = 0;
	long long avg_x = 0, avg_y = 0;
	for(int tests = 1; tests <= test_count; tests++){
		fstream input(("./testcases/" + to_string(tests) + ".in").c_str());
		fstream answer(("./" + string(argv[1]) + "/" + to_string(tests) + ".out").c_str());
		int N, D;
		input >> N >> D;
		cerr << "n is " << N << " and D is " << D << "\n";
		vector<pair<int, int>> points(N);
		for(int i = 0; i<N; i++){
			input >> points[i].first >> points[i].second;
		}
		vector<int> p(N);
		for(int i = 0; i<N; i++){
			answer >> p[i];
		}
		long long currentx = points[p[0]].first, currenty = points[p[0]].second;
		for(int i = 1; i<N; i++){
			currentx += abs(points[p[i]].first - points[p[i-1]].first);
			currenty += abs(points[p[i]].second - points[p[i-1]].second);
		}
		worst_case = max(worst_case, currentx + currenty);
		avg_x += currentx;
		avg_y += currenty;
		avg_case += currentx + currenty;
		input.close();
		answer.close();
	}
	avg_x /= test_count; //round down since decimals dont really matter at this scale
	avg_y /= test_count;
	avg_case /= test_count; 
	//worst case
	//avg case
	//avg x
	//avg y
	cout << worst_case << "\n" << avg_case << "\n" << avg_x << "\n" << avg_y << "\n";
	return 0;
}

