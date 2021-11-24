#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5 + 5;
int dp[mxN][25][3];

void solve() {
    int N, K; cin >> N >> K;
    vector<int> moves;
    moves.push_back(-1);
    for(int i = 1; i <= N; i++) {
        char c; cin >> c;
        if(c == 'P') {
            moves.push_back(0);
        }else if(c == 'H') {
            moves.push_back(1);
        }else {
            moves.push_back(2);
        }
    }
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            for(int k = 0; k < 3; k++) {
                int cost = (int) (moves[i] == k);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if(j - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
                if(j - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][(k + 1) % 3]);
                if(j - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][(k + 2) % 3]);
                dp[i][j][k] += cost;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            for(int k = 0; k < 3; k++) {
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

