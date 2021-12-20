#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5 + 5;
vector<int> adj[mxN];
bool visited[mxN];
vector<int> ans;

void dfs(int s) {
	if(visited[s]) return;
	ans.push_back(s);
	visited[s] = true;
	for(auto &x : adj[s]) {
		dfs(x);
	}
}

void solve() {
    //at most, there will be 2 nodes next to a certain person
    //at least, there will be 1 node next to a certain person
    //if we dfs, and we just append that certain element, is it guaranteed to form a correct sequence?
    //start at the nodes with indegree of 1
    //
    //is it always possible, given that the indegree of every node is 2 or less?
	int N, M; cin >> N >> M;
	map<int, int> cnt;
	bool ok = 1;
	vector<pair<int, int>> queries;
	for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; x--, y--;
	queries.push_back({x, y});
        adj[x].push_back(y);
        adj[y].push_back(x);
	}
	for(int i = 0; i < N; i++) {
		if(adj[i].size() == 1) {
			dfs(i);
		}
	}
	for(int i = 0; i < N; i++) {
		if(!visited[i]) {
			ans.push_back(i);
		}
	}
	//check adjacencies
	map<pair<int, int>, bool> adjacencies;
	for(int i = 0; i < N - 1; i++) {
		adjacencies[make_pair(ans[i], ans[i + 1])] = true;
		adjacencies[make_pair(ans[i + 1], ans[i])] = true;
	}
	for(auto &x : queries) {
		if(!adjacencies[make_pair(x.first, x.second)]) {
			ok = 0;
		}
	}
	cout << (ok ? "Yes\n" : "No\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
