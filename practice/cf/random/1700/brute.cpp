#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int mx = LLONG_MIN;
    vector<pair<int, int>> ans;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if((i + 1) * (j + 1) - K * (A[i] | A[j]) > mx) {
                mx = (i + 1) * (j + 1) - K * (A[i] | A[j]);
                ans.clear();
                ans.push_back({i, j});
                continue;
            }
            if((i + 1) * (j + 1) - K * (A[i] | A[j]) == mx) {
                ans.push_back({i, j});
            }
        }
    }
    cout << mx << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

