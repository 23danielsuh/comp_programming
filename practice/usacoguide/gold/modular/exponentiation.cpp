#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD int64_t (1e9 + 7)

int64_t mod_pow(int64_t a, int64_t b) {
    int ans = 1;
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
        int64_t a, b; cin >> a >> b;
        cout << mod_pow(a, b) << "\n";
    }
}

