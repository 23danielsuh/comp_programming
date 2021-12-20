#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

queue<pair<int, int>> q;
int vis = 0;

void dfs(int u, vector<vector<int>> &visited, vector<vector<int>> &adj_1, vector<vector<int>> &adj_2, bool color) {
	if(visited[u][color] != -1) { vis += visited[u][color]; return; }
	visited[u][color] = 0;
	q.push({u, color});
	vis++;
	if(!color) {
		//use adj_1
		for(auto &x : adj_1[u]) {
			dfs(x, visited, adj_1, adj_2, !color);
		}
	}else {
		for(auto &x : adj_2[u]) {
			dfs(x, visited, adj_1, adj_2, !color);
		}
	}
}

void solve() {
	int N; cin >> N;
	vector<vector<int>> visited(N + 5); for(auto &x : visited) x.resize(2);
	for(auto &x : visited) for(auto &y : x) y = -1;
	vector<vector<int>> adj_1(N + 5); 
	vector<vector<int>> adj_2(N + 5); 
	string S; cin >> S;
	for(int i = 1; i <= N; i++) {
		if(S[i - 1] == 'L') {
			adj_1[i].push_back(i - 1);
			adj_2[i - 1].push_back(i);
		}else {
			adj_2[i].push_back(i - 1);
			adj_1[i - 1].push_back(i);
		}
	}
	for(int i = 0; i <= N; i++) {
		vis = 0;
		q.push({i, 0});
		dfs(i, visited, adj_1, adj_2, 0);
		while(!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			visited[cur.first][cur.second] = vis;
		}
		cout << vis << " ";
	}
	cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

