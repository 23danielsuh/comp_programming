#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 505;
int grid[mxN][mxN];
int N;

struct DSU {
	vector<int> e;
	DSU(int W) { e = vector<int>(W, -1); }

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

bool vis[mxN][mxN];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool valid(int x) {
    return x >= 0 && x < N;
}

void BFS(int r, int c, DSU &dsu, int max_dist) {
    queue<pair<int, int>> q;
    q.push({r, c});
    vis[r][c] = true;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(valid(cur.first + dx[i]) && valid(cur.second + dy[i]) && !vis[cur.first + dx[i]][cur.second + dy[i]]) {
                if(abs(grid[cur.first][cur.second] - grid[cur.first + dx[i]][cur.second + dy[i]]) <= max_dist) {
                    q.push({cur.first + dx[i], cur.second + dy[i]});
                    vis[cur.first + dx[i]][cur.second + dy[i]] = true;
                    dsu.unite(r * N + c, (cur.first + dx[i]) * N + cur.second + dy[i]);
                }
            }
        }
    }
}

bool check(int max_dist) {
    memset(vis, 0, sizeof vis);
    DSU dsu(N * N);
    int mxSize = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!vis[i][j]) {
                BFS(i, j, dsu, max_dist);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            mxSize = max(mxSize, dsu.size(i * N + j));
        }
    }
    return mxSize >= (N * N + 1) / 2;
}

int bin_search() {
    int lo = 0, hi = INT_MAX;
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
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    cout << bin_search() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

