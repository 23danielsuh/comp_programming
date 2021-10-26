#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> A;

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

bool check(int dist) {
    DSU dsu(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x1 = A[i].first, x2 = A[j].first, y1 = A[i].second, y2 = A[j].second;
            if(dist >= (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) {
                dsu.unite(i, j);
            }
        }
    }
    return dsu.size(0) == n;
}

int bin_search() {
    int lo = 0, hi = 1e9 + 7;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(check(mid)) {
            hi = mid;
        }else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solve() {
    cin >> n;
    A.resize(n); for(auto &x : A) cin >> x.first >> x.second;
    cout << bin_search() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

