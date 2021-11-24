#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 1e5 + 5;
vector<pair<int, int>> adj[mxN];
int dist[mxN][2]; 
int N;

void dijkstra(int src) { 
	for(int i = 0; i < N; ++i) for(int j = 0; j < 2; j++) dist[i][j] = LLONG_MAX;

	using T = pair<ll, pair<int, int>>; priority_queue<T, vector<T>, greater<T>> pq;
	dist[src][0] = dist[src][1] = 0; 
	pq.push({0, make_pair(src, 0)});

	while(pq.size()) {
        ll cdist = pq.top().first;
        int node = pq.top().second.first;
        int halved = pq.top().second.second;
        pq.pop();
		if(cdist != dist[node][halved]) continue;
		for(pair<int, int> i : adj[node]) {
			if(cdist + i.second < dist[i.first][halved]) {
				pq.push({dist[i.first][halved] = cdist + i.second, make_pair(i.first, halved)});
			}
            if(cdist + i.second / 2 < dist[i.first][1] && halved == 0) {
				pq.push({dist[i.first][1] = cdist + i.second / 2, make_pair(i.first, 1)});
            }
		}
	}
}

void solve() {
    int M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        adj[a].push_back({b, w});
    }
    dijkstra(0);
    cout << dist[N - 1][1] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

