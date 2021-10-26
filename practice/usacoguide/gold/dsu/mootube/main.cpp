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
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

void solve() {
    int N, Q; cin >> N >> Q;
    DSU dsu(N);
    vector<pair<pair<int, int>, int>> edges(N - 1);
    for(int i = 0; i < N - 1; i++) {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        edges[i].first.first--, edges[i].first.second--;
    }
    vector<pair<pair<int, int>, int>> queries(Q);
    for(int i = 0; i < Q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].first.second--;
        queries[i].second = i;
    }
    sort(edges.begin(), edges.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
        return a.second > b.second;
    });
    sort(queries.begin(), queries.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
        return a.first.first > b.first.first;
    });
    int idx = 0;
    vector<int> ans(Q);
    for(int i = 0; i < Q; i++) {
        int K = queries[i].first.first, start = queries[i].first.second;
        while(idx < N - 1 && K <= edges[idx].second) {
            int node1 = edges[idx].first.first;
            int node2 = edges[idx].first.second;
            dsu.unite(node1, node2);
            idx++;
        }
        ans[queries[i].second] = dsu.size(start) - 1;
    }
    for(auto &x : ans) cout << x << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

