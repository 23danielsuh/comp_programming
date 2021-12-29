
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
	int N; cin >> N;
	vector<vector<int>> adj(N + 5);
	vector<int> indegree(N + 5);
	for(int i = 0; i < N; i++) {
		int K; cin >> K;
		for(int j = 0; j < K; j++) {
			int x; cin >> x;
			adj[x].push_back(i + 1);
			indegree[i + 1]++;
		}
	}
	queue<int> q;
	vector<int> dist(N + 5, -1e9);
	for(int i = 1; i <= N; i++) {
		if(indegree[i] == 0) {
			q.push(i);
			dist[i] = 0;
		}
	}
	vector<int> order;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		order.push_back(cur);
		for(auto &x : adj[cur]) {
			indegree[x]--;
			if(indegree[x] == 0) {
				q.push(x);
			}
		}
	}
	if((int) order.size() != N) {
		cout << -1 << "\n";
		return;
	}
	for(int i = 0; i < N; i++) {
		int cur = order[i];
		if(dist[cur] >= 0) {
			for(auto &x : adj[cur]) {
				//calculate weights here
				if(cur > x) {
					if(dist[cur] + 1 > dist[x]) {
						dist[x] = dist[cur] + 1;
					}
				}else {
					if(dist[cur] > dist[x]) {
						dist[x] = dist[cur];
					}
				}
			}
		}
	}
	int mx = 0;
	for(int i = 1; i <= N; i++) {
		mx = max(mx, dist[i]);
	}
	cout << mx + 1 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

