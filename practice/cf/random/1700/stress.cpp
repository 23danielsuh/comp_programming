// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    cout << 1 << "\n";
    int n = rand(2, 10), k = 2;
    printf("%d %d\n", n, k);
    vector<int> used;
    for(int i = 0; i < n; ++i) {
        cout << rand(0, n) << " ";
    }
    puts("");
}
