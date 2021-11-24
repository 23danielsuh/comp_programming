#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 5005;
int dp[mxN][mxN];

void solve() {
    for(auto &x : dp) for(auto &y : x) y = INT_MAX;
    //memset(dp, 0, sizeof dp);
    string S, T; cin >> S >> T;
    int N = (int) S.size(), M = (int) T.size();
    for(int i = 0; i <= N; i++) {
        dp[i][0] = i;
    }
    for(int i = 0; i <= M; i++) {
        dp[0][i] = i;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (int) (S[i - 1] != T[j - 1]));
        }
    }
    cout << dp[N][M] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
