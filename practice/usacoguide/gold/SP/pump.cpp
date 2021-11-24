#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

vector<pair<int, pair<int, int>>> graph[100000];
// Adjacency list of (neighbour, edge weight)
ll dist[100000];
int N;

void dijkstra(int src, int min_flow) { // Source and destination
	for (int i = 0; i < N; ++i) dist[i] = LLONG_MAX;
	// Set all distances to infinity

	using T = pair<ll,int>; priority_queue<T,vector<T>,greater<T>> pq;
	dist[src] = 0; // The shortest path from a node to itself is 0
	pq.push({0, src});

	while (pq.size()) {
		ll cdist; int node; tie(cdist, node) = pq.top(); pq.pop();
		if (cdist != dist[node]) continue;
		for (pair<int, pair<int, int>> i : graph[node]) {
			// If we can reach a neighbouring node faster,
			// we update its minimum distance
			if (i.second.second >= min_flow && cdist+i.second.first < dist[i.first]) {
				pq.push({dist[i.first] = cdist+i.second.first, i.first});
			}
		}
	}
}

void solve() {
    int M; cin >> N >> M;
    vector<int> flow_rates;
    for(int i = 0; i < M; i++) {
        int x, y, w, f; cin >> x >> y >> w >> f; x--, y--;
        graph[x].push_back({y, make_pair(w, f)});
        graph[y].push_back({x, make_pair(w, f)});
        flow_rates.push_back(f);
    }
    int ans = 0;
    for(int &x : flow_rates) {
        dijkstra(0, x);
        ans = max(ans, (int) (((double) x / (double) dist[N - 1]) * 1000000));
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

