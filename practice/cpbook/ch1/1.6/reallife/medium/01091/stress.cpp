// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = 100000;
    printf("%d\n", n);
    for(int i = 0; i < n; ++i) {
        cout << rand(1, 100);
    }
    cout << 0;
    puts("");
}
