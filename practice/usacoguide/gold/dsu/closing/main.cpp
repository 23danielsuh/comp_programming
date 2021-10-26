#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};

const int mxN = 2e5 + 5;
vector<int> adj[mxN];
bool visited[mxN];

void solve() {
    int N, M; cin >> N >> M;
    DSU dsu(N);
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    vector<int> order(N); for(auto &x : order) cin >> x;
    reverse(order.begin(), order.end());
    vector<string> ans;
    for(int i = 0; i < N; i++) {
        order[i]--;
        int num_nodes = i + 1;
        for(auto &u : adj[order[i]]) {
            if(visited[u]) {
                dsu.unite(order[i], u);
            }
        }
        if(dsu.size(order[i]) == num_nodes) {
            ans.push_back("YES");
        }else {
            ans.push_back("NO");
        }
        visited[order[i]] = true;
    }
    reverse(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
