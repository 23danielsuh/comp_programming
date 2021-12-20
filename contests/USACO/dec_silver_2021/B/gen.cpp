// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int T = rand(2, 10);
    printf("%d\n", T);
	while(T--) {
		int N = rand(2, 10), M = rand(2, 10);
		if(M >= N * (N + 1) / 2) {
			T++;
			continue;
		}
		printf("%d %d\n", N, M);
		map<pair<int, int>, bool> used;
		for(int i = 0; i < M; ++i) {
			int x = rand(1, N), y = rand(1, N);
			while(x != y && used[make_pair(x, y)] || used[make_pair(y, x)]) {
				x = rand(1, N), y = rand(1, N);
			}
			printf("%d %d\n", x, y);
			used[make_pair(x, y)] = true;
			used[make_pair(y, x)] = true;
		}
		puts("");
	}
}
