// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 1000000);
    printf("%d\n", n);
    for(int i = 0; i < n; ++i) {
        cout << rand(1, 1000000000) << " " << rand(1, 1000000000) << "\n";
    }
    puts("");
}
