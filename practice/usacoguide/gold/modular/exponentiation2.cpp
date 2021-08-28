#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int64_t bin_exp(int64_t a, int64_t b, int64_t MOD) {
    int64_t ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int64_t a, b, c; cin >> a >> b >> c;
        cout << bin_exp(a, bin_exp(b, c, int64_t(1e9 + 7 - 1)), int64_t(1e9 + 7)) << "\n";
    }
}

