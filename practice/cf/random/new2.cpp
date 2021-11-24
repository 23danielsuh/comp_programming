#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string ans;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> A(K); for(auto &x : A) cin >> x.first >> x.second;
    vector<pair<int, int>> B(K); for(auto &x : B) cin >> x.first >> x.second;
    for(int i = 0; i < M - 1; i++) {
        ans += 'L';
    }
    for(int i = 0; i < N - 1; i++) {
        ans += 'U';
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M - 1; j++) {
            if(i & 1) {
                ans += 'L';
            }else {
                ans += 'R';
            }
        }
        if(i != N - 1) ans += 'D';
    }
    cout << (int) ans.size() << "\n" << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

