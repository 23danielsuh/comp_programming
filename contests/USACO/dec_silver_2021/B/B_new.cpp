#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int find_closest1(int x, set<int> &cur) {
	auto it = cur.lower_bound(x);
	int ret = 1e16;
	if(it != cur.end()) {
		ret = min(ret, (*it - x) * (*it - x));
	}
	if(it != cur.begin()) {
		--it;
		ret = min(ret, (*it - x) * (*it - x));
	}
	return ret;
}

void dfs1(int s, vector<vector<int>> &adj_list, vector<bool> &vis, set<int> &cur) {
	if(vis[s]) return;
	vis[s] = true;
	cur.insert(s);
	for(auto &x : adj_list[s]) {
		dfs1(x, adj_list, vis, cur);
	}
}

int dist1 = 1e16, dist2 = 1e16;

void dfs2(int s, vector<vector<int>> &adj_list, vector<bool> &vis, set<int> &component_1, set<int> &component_2) {
	if(vis[s]) return;
	vis[s] = true;
	dist1 = min(dist1, find_closest1(s, component_1));
	dist2 = min(dist2, find_closest1(s, component_2));
	for(auto &x : adj_list[s]) {
		dfs2(x, adj_list, vis, component_1, component_2);
	}
}

void solve() {
	set<int> component_1, component_2;
	int ans = 1e16; dist1 = 1e16, dist2 = 1e16;
	int N, M; cin >> N >> M;
	vector<vector<int>> adj_list(N + 5);
	vector<bool> vis(N + 5, 0);
	for(int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	dfs1(1, adj_list, vis, component_1);
	dfs1(N, adj_list, vis, component_2);
	
	//checking direct connection between component 1 and component 2
	for(auto &x : component_1) {
		ans = min(ans, find_closest1(x, component_2));
	}

	//checking connection between component 1 -> component x -> component 2
	for(int i = 1; i <= N; i++) {
		if(!vis[i]) {
			dist1 = 1e16, dist2 = 1e16;
			dfs2(i, adj_list, vis, component_1, component_2);
			ans = min(ans, dist1 + dist2);
		}
	}
	
	if(ans == 1e16) {
		cout << 0 << "\n"; //idk why this works but sure
		return;
	}
	cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	for(int i = 1; i <= T; i++) {
		solve();
	}
}

