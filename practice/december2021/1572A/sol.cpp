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
	vector<int> use_later;
	for(int i = 1; i <= N; i++) {
		if(indegree[i] == 0) {
			q.push(i);
			use_later.push_back(i);
		}
	}
	int sz = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		sz++;
		for(auto &x : adj[cur]) {
			indegree[x]--;
			if(indegree[x] == 0) {
				q.push(x);
			}
		}
	}
	if(sz != N) {
		cout << -1 << "\n";
		return;
	}
	//should be possible
	auto BFS = [&]() -> int {
		vector<int> dist(N + 5, -1e9);
		while(!q.empty()) q.pop();
		for(auto &x : use_later) {
			q.push(x);
			dist[x] = 0;
		}
		assert(!q.empty());
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for(auto &x : adj[cur]) {
				if(cur > x) {
					if(dist[cur] + 1 > dist[x]) {
						dist[x] = dist[cur] + 1;
						q.push(x);
					}
				}else {
					if(dist[cur] > dist[x]) {
						dist[x] = dist[cur];
						q.push(x);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			ans = max(ans, dist[i] + 1);
		}
		return ans;
	};
	cout << BFS() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

