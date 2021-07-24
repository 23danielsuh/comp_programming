#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 40005;
vector<int> adj[mxN];

vector<int> bfs(int node) {
    vector<int> ret(mxN, INT_MAX);
    queue<int> q; q.push(node);
    ret[node] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &u : adj[cur]) {
            if(ret[cur] + 1 < ret[u]) {
                q.push(u);
                ret[u] = ret[cur] + 1;
            }
        }
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("piggyback/11.in", "r", stdin);
    int B, E, P, N, M; cin >> B >> E >> P >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> bessie_dist = bfs(1);
    vector<int> elsie_dist = bfs(2);
    vector<int> ans_dist = bfs(N);
    ll ans = INT_MAX;
    for(int i = 1; i <= N; i++) {
        ans = min(ans, bessie_dist[i] * B + elsie_dist[i] * E + ans_dist[i] * P);
    }
    cout << ans;
}
