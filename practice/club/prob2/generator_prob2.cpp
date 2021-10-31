#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    int t = 100;
    cout << t << "\n";
    while(t--) {
        int n = rand(1, 100), d = rand(1, 100);
        printf("%d %d\n", n, d);
        for(int i = 0; i < n; ++i) {
            int x;
            x = rand(1, 1000);
            printf("%d ", x);
        }
        puts("");
    }
}
 