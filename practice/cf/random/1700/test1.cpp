#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e5 + 5;
vector<int> adj[mxN];
bool visited[mxN];

int l, r;

void dfs(int s) {
    if(visited[s]) return;
    visited[s] = true;
    l = min(l, s), r = max(r, s);
    for(auto &u : adj[s]) {
        dfs(u);
    }
}

void solve() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<pair<int, int>> con_comp;
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            l = i, r = i;
            dfs(i);
            con_comp.push_back({l, r});
        }
    }
    sort(con_comp.begin(), con_comp.end());
    int cur_max = INT_MIN, ans = 0;
    for(auto &x : con_comp) {
        if(x.first <= cur_max) {
            ans++;
        }
        cur_max = max(cur_max, x.second);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
