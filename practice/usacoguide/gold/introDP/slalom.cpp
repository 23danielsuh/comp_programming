#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 105;
int grid[mxN][mxN], dp[mxN][mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("slalom.in", "r", stdin);
    //freopen("slalom.out", "w", stdout);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> grid[i][j];
        }
    }
    for(auto &x : dp) for(auto &y : x) y = INT_MIN;
    dp[0][0] = grid[0][0];
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + grid[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + grid[i + 1][j + 1]);
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < N; i++) {
        ans = max(ans, dp[N - 1][i]);
    }
    cout << ans;
}

