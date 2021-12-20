// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
	int K = rand(1, 1000);
	int M = rand(1, 3);
	int N = rand(1, 2e5);
	cout << K << " " << M << " " << N << "\n";
	set<int> used;
	for(int i = 0; i < K; i++) {
		int p = rand(0, 1e9);
		if(used.count(i)) continue;
		int t = rand(0, 1e9);
		cout << p << " " << t << "\n";
		used.insert(i);
	}
	for(int i = 0; i < M; i++) {
		int f = rand(0, 1e9);
		if(used.count(f)) continue;
		cout << f << "\n";
	}
}
