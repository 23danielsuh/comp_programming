#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5 + 5;
int n, m;
vector<int> ordering;
vector<array<int, 3>> adj;
vector<int> out_of_order;

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

bool check(int width) {
    DSU dsu(n);
    for(int i = 0; i < m; i++) {
        int a = adj[i][0], b = adj[i][1], w = adj[i][2];
        if(w >= width) {
            dsu.unite(a, b);
        }
    }
    for(int i = 0; i < n; i++) {
        if(ordering[i] != i + 1) {
            if(!dsu.same_set(ordering[i] - 1, i)) return false;
        }
    }
    return true;
}

int bin_search() {
    int lo = 0, hi = 1e9 + 9;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if(check(mid)) {
            lo = mid;
        }else {
            hi = mid - 1;
        }
    }
    return lo;
}

void solve() {
    cin >> n >> m;
    ordering.resize(n);
    for(auto &x : ordering) cin >> x;
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        adj.push_back({a, b, w});
    }
    for(int i = 0; i < n; i++) {
        if(ordering[i] != i + 1) {
            out_of_order.push_back(i);
        }
    }
    if(out_of_order.empty()) { cout << -1 << "\n"; return; }
    cout << bin_search() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

