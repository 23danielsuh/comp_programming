#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<pair<int, int>, int>> graph[105][105];
// Adjacency list of (neighbour, edge weight)
ll dist[105][105];
int cost[105][105];
int N, TT;
int dx[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int dy[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

bool check(int x) {
    return x >= 0 && x < N;
}

ll ans = LLONG_MAX;

void dijkstra(pair<int, int> src) { // Source and destination
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dist[i][j] = LLONG_MAX;
        }
    }
	// Set all distances to infinity

    using T = pair<ll, pair<int, int>>; priority_queue<T, vector<T>, greater<T>> pq;
    dist[src.first][src.second] = 0;
	pq.push({0, src});

	while (pq.size()) {
        ll cdist = pq.top().first;
        pair<int, int> node = pq.top().second; pq.pop();
        if(cdist != dist[node.first][node.second]) continue;
        int end_dist = abs((N - 1) - node.first) + abs((N - 1) - node.second);
        if(end_dist <= 2) {
            ans = min(ans, cdist + end_dist * TT);
        }
        for(int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
            if(check(node.first + dx[i]) && check(node.second + dy[i])) {
                pair<pair<int, int>, int> neighbor;
                neighbor.first = {node.first + dx[i], node.second + dy[i]};
                neighbor.second = cost[node.first + dx[i]][node.second + dy[i]] + 3 * TT;
                if(cdist + neighbor.second < dist[node.first + dx[i]][node.second + dy[i]]) {
                    pq.push({dist[node.first + dx[i]][node.second + dy[i]] = cdist + neighbor.second, neighbor.first});
                }
            }
        }
	}
}

void solve() {
    cin >> N >> TT;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
    dijkstra({0, 0});
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

