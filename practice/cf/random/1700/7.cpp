#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N, M, K; cin >> N >> M >> K;
    //n and m can not both be odd
    //if n is odd, then you have to have a layer of m / 2 blocks minimum, so that you can account for the extra 1
    //m / 2, 3 * m / 2, 5 * m / 2, etc. -> have to have an odd amount of blocks
    //  
    if(N % 2 == 0 && M % 2 == 0) {
        if(K % 2 == 0) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
        return;
    }
    int kh = K, kv = (N * M) / 2 - K;
    if(N & 1) {
        kh -= M / 2;
        if(kh < 0 || kh & 1) {
            cout << "NO\n";
            return;
        }
    }else if(M & 1) {
        kv -= N / 2;
        if(kv < 0 || kv & 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

