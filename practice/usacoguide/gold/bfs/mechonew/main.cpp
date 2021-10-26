#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 805;
int N, S; 
char grid[mxN][mxN];
int dist[mxN][mxN];
int mecho_dist[mxN][mxN];
pair<int, int> start, finish;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool check(int seconds) {
    for(auto &x : mecho_dist) for(auto &y : x) y = INT_MAX;
    queue<pair<pair<int, int>, int>> q;
    int bees = seconds;
    if(bees < dist[start.first][start.second]) {
        q.push({make_pair(start.first, start.second), 0});
        mecho_dist[start.first][start.second] = 0;
    }
    
    unordered_map<int, bool> considered;
    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int cur = q.front().second; 
        if(x == finish.first && y == finish.second) return true;
        if(cur % S == 0 && cur != 0 && !considered[cur]) {
            bees++;
            considered[cur] = true;
            continue;
        }
        q.pop();
        if(bees >= dist[x][y]) continue;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N && bees < dist[x + dx[i]][y + dy[i]] 
                    && mecho_dist[x][y] + 1 < mecho_dist[x + dx[i]][y + dy[i]] && (grid[x + dx[i]][y + dy[i]] == 'G' 
                    || grid[x + dx[i]][y + dy[i]] == 'D')) {
                
                mecho_dist[x + dx[i]][y + dy[i]] = mecho_dist[x][y] + 1;
                q.push({make_pair(x + dx[i], y + dy[i]), cur + 1});
            }
        }
    }
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         if(mecho_dist[i][j] == INT_MAX) {
    //             cout << -1 << " ";
    //         }else {
    //             cout << mecho_dist[i][j] << " ";
    //         }
    //     }
    //     cout << "\n";
    // }
    return false;
}

int bin_search() {
    int lo = 0, hi = 2 * N * N;
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

void preprocess() {
    for(auto &x : dist) for(auto &y : x) y = INT_MAX;
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 'H') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N && dist[x][y] + 1 < dist[x + dx[i]][y + dy[i]]
                    && grid[x + dx[i]][y + dy[i]] == 'G') {
                q.push({x + dx[i], y + dy[i]});
                dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
            }
        }
    }
    dist[finish.first][finish.second] = INT_MAX;
}

void solve() {
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'M') {
                start.first = i, start.second = j;
                grid[i][j] = 'G';
            }else if(grid[i][j] == 'D') {
                finish.first = i, finish.second = j;
            }
        }
    }
    preprocess();
    int ans;
    ans = bin_search();
    if(!check(0)) {
        ans = -1;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}


