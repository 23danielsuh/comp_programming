#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 1005;
int dp[mxN][mxN];
bool visiting[mxN][mxN];
vector<int> adj[mxN], in_adj[mxN];
vector<int> cost(mxN);

void solve() {
    int N, M, C; cin >> N >> M >> C;
    for(int i = 1; i <= N; i++) {
        cin >> cost[i];
    }
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        in_adj[y].push_back(x);
    }
    memset(visiting, 0, sizeof visiting);
    memset(dp, 0, sizeof dp);
    visiting[1][1] = true;
    //dp[time][index]
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= N; j++) {
            if(visiting[i][j]) {
                for(auto &a : in_adj[j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][a] + cost[j]);
                }
                for(auto &a : adj[j]) {
                    visiting[i + 1][a] = true;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= 1000; i++) {
        if(dp[i][1] - (C * (i - 1) * (i - 1)) > ans) {
            ans = max(ans, dp[i][1] - (C * (i - 1) * (i - 1)));
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

