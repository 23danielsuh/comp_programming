#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 105, mxW = 1e5 + 5;
int64_t dp[mxN][mxW];

void solve() {
    int N, W; cin >> N >> W;
    vector<pair<int, int>> A(N + 1); 
    for(int i = 1; i <= N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - A[i].first >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i].first] + A[i].second);
        }
    }
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= W; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[N][W] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}