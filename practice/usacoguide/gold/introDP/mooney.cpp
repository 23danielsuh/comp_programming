#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN], weight(mxN);

//current node, current day
int dp[1005][1005];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int N, M, C; cin >> N >> M >> C;
    for(int i = 0; i < N; i++) cin >> weight[i];
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
    }
    for(auto &x1 : dp) {
        for(auto &x2 : x1) {
            x2 = -1;
        }
    }
    dp[0][0] = 0;
    int ans = 0;
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[i][j] == -1) {
                continue;
            }
            if(j == 0) {
                ans = max(ans, dp[i][j] - C * i * i);
            }
            for(auto &u : adj[j]) {
                dp[i + 1][u] = max(dp[i + 1][u], dp[i][j] + weight[u]);
            }
        }
    }
    cout << ans << "\n";
}
