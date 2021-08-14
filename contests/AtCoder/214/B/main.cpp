#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int S, T; cin >> S >> T;
    int sum = 0;
    for(int a = 0; a <= 100; a++) {
        for(int b = 0; b <= 100; b++) {
            for(int c = 0; c <= 100; c++) {
                if(a + b + c <= S && a * b * c <= T) {
                    sum++;
                }
            }
        }
    }
    cout << sum << "\n";
}

