// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
	int N = rand(1, 5000), M = rand(1, 5000);
	printf("%d %d\n", N, M);
	for(int i = 0; i < N; ++i) {
		int x = rand(1, M), y = rand(1, M);
		printf("%d %d\n", x, y);
	}
	puts("");
}
