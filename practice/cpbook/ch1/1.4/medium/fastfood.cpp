#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        vector<pair<vector<int>, int>> prize(N);
        for(int i = 0; i < N; i++) {
            int K; cin >> K;
            prize[i].first.resize(K);
            for(auto &x : prize[i].first) cin >> x;
            int cash; cin >> cash;
            prize[i].second = cash;
        }
        vector<int> stickers(M); for(auto &x : stickers) cin >> x;
        int ans = 0;
        for(int i = 0; i < N; i++) {
            int pos = INT_MAX;
            for(auto &x : prize[i].first) {
                pos = min(pos, stickers[x - 1]);
            }
            ans += pos * prize[i].second;
        }
        cout << ans << "\n";
    }
}

