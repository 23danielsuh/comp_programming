#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e5 + 5, MOD = 1e9 + 7;
int dp[mxN], dist[mxN];
vector<int> adj[mxN];

void bfs() {
    queue<int> q;
    q.push(1);
    for(auto &x : dist) x = INT_MAX;
    for(auto &x : dp) x = 0;
    dist[1] = 1, dp[1] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &u : adj[cur]) {
            if(dist[cur] + 1 < dist[u]) {
                dist[u] = dist[cur] + 1;
                q.push(u);
            }
            if(dist[u] + 1 == dist[cur]) {
                dp[cur] += dp[u]; dp[cur] %= MOD;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    cout << dp[N] << "\n";
}
