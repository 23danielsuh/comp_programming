#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int ans = 0;
set<int> endNode, beginNode;

int distToNode1 = LLONG_MAX, distToNodeN = LLONG_MAX;

void find_dists(int s, vector<vector<int>> &adj_list, vector<bool> &vis) {
	if(vis[s]) return;
	vis[s] = true;

	//processing node s
	auto dist1 = beginNode.lower_bound(s);
	if(dist1 != beginNode.end()) {
		distToNode1 = min(distToNode1, abs(*dist1 - s));
	}
	if(dist1 != beginNode.begin()) {
		--dist1;
		distToNode1 = min(distToNode1, abs(*dist1 - s));
	}

	auto distN = endNode.lower_bound(s)	;
	if(distN != endNode.end()) {
		distToNodeN = min(distToNodeN, abs(*distN - s));
	}
	if(distN != endNode.begin()) {
		--distN;
		distToNodeN = min(distToNodeN, abs(*distN - s));
	}
	
	for(auto &x : adj_list[s]) {
		find_dists(x, adj_list, vis);
	}
}

set<int> st;

void createSets(int s, vector<vector<int>> &adj_list, vector<bool> &vis) {
	if(vis[s]) return;
	vis[s] = true;
	st.insert(s);
	for(auto &x : adj_list[s]) {
		createSets(x, adj_list, vis);
	}
}

void solve() {
	beginNode.clear(); endNode.clear();
	st.clear();
	distToNode1 = INT_MAX, distToNodeN = INT_MAX, ans = INT_MAX;
	int N, M; cin >> N >> M;
	vector<vector<int>> adj_list(N + 100); 
	vector<bool> vis(N + 100, 0);
	for(int i = 0; i < M; i++) {
		int x, y; cin >> x >> y; 
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	createSets(1, adj_list, vis);
	if(vis[1] && vis[N]) {
		cout << 0 << "\n";
		return;
	}
	beginNode = st;
	st.clear();
	createSets(N, adj_list, vis);
	endNode = st;
	st.clear();
	ans = LLONG_MAX;
	for(auto &x : beginNode) {
		auto it = endNode.lower_bound(x);
		if(it != endNode.end()) {
			ans = min(ans, (*it - x) * (*it - x));
		}
		if(it != endNode.begin()) {
			--it;
			ans = min(ans, (*it - x) * (*it - x));
		}
	}
	for(int i = 1; i <= N; i++) {
		distToNode1 = LLONG_MAX, distToNodeN = LLONG_MAX;
		if(!vis[i]) {
			find_dists(i, adj_list, vis);
			ans = min(ans, distToNode1 * distToNode1 + distToNodeN * distToNodeN);
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		solve();
	}
}
