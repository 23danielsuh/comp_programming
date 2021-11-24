#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> L;
    L.push_back({INT_MAX, 0});
    for(int i = 1; i <= M; i++) {
        int x; cin >> x;
        L.push_back({x, i});
    }
    //sort(L.begin(), L.end(), greater<pair<int, int>>());
    int min_dist = M - 1 + L[M].first;
    int extend_length = N - min_dist;
    vector<int> ans(M + 1);
    for(int i = 1; i <= M; i++) {
        //it has to be in the range of [l, r]
        //you want to optimally choose index i...
        cout << extend_length << "\n";
        if(i != 1 && extend_length > 0) {
            int can_move = L[i - 1].first - 1;
            ans[i] = ans[i - 1] + min(can_move + 1, extend_length);
            extend_length -= min(can_move, extend_length);
        }
        if(i == 1) {
            ans[i] = 1;
        }
    }
    for(int i = 1; i <= M; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
     //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
