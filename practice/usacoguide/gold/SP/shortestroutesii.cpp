#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 505;
int dist[mxN][mxN], edges[mxN][mxN];

void solve() {
    int N, M, Q; cin >> N >> M >> Q;
    for(auto &x : edges) for(auto &y : x) y = 1e18;
    for(int i = 0; i < M; i++) {
        int x, y, w; cin >> x >> y >> w;
        edges[x][y] = min(edges[x][y], w);
        edges[y][x] = min(edges[y][x], w);
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) dist[i][j] = 0;
            else if(!edges[i][j]) dist[i][j] = 1e18;
            else dist[i][j] = edges[i][j];
        }
    }
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(Q--) {
        int a, b; cin >> a >> b;
        cout << (dist[a][b] >= 1e18 ? -1 : dist[a][b]) << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

