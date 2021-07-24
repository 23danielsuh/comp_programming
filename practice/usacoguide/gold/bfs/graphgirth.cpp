#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2505;
vector<int> adj[mxN];
int dist[mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= N; i++) {
        queue<int> q;
        for(auto &x : dist) x = -1;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";
            for(auto &u : adj[node]) {
                if(dist[u] == -1) {
                    dist[u] = dist[node] + 1;
                    q.push(u);
                }else if(dist[u] >= dist[node]) {
                    ans = min(ans, 1 + dist[u] + dist[node]);
                }
            }
        }
        cout << "\n";
        cout << ans << "\n";
    }
    if(ans == INT_MAX) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
}
