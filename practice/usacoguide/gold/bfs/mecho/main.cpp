#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 805;
int N, S; 
char grid[mxN][mxN], store_grid[mxN][mxN];
int dist[mxN][mxN];
bool visited[mxN][mxN];
pair<int, int> start, finish;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool check(int seconds) {
    // Can you just simulate the first w seconds and then find the BFS thing?
    //O(N^2)
    memset(visited, 0, sizeof visited);
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++)
            grid[i][j] = store_grid[i][j];
    
    //O(N^2)
    queue<pair<pair<int, int>, int>> bees;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 'H') {
                bees.push({make_pair(i, j), 0});
            }
        }
    }

    //O(< N^2)
    while(!bees.empty()) {
        int x = bees.front().first.first, y = bees.front().first.second;
        int cur = bees.front().second;
        bees.pop();
        if(cur > seconds) continue;
        grid[x][y] = 'H';
        for(int it = 0; it < 4; it++) {
            if(x + dx[it] >= 0 && x + dx[it] < N && y + dy[it] >= 0 && y + dy[it] < N && grid[x + dx[it]][y + dy[it]] == 'G' && !visited[x + dx[it]][y + dy[it]]) {
                bees.push({make_pair(x + dx[it], y + dy[it]), cur + 1});
                visited[x + dx[it]][y + dy[it]] = true;
            }
        }
    }
    
    queue<pair<pair<int, int>, int>> q;
    for(auto &x : dist) for(auto &y : x) y = INT_MAX;
    q.push({make_pair(start.first, start.second), 0});
    dist[start.first][start.second] = 0;
    unordered_map<int, bool> considered;
    while(!q.empty()) {
        if(q.front().second % S == 0 && q.front().second != 0 && !considered[q.front().second]) {
            vector<pair<int, int>> change;
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    if(grid[j][k] == 'H') {
                        for(int it = 0; it < 4; it++) {
                            if(j + dx[it] >= 0 && j + dx[it] < N && k + dy[it] >= 0 && k + dy[it] < N && grid[j + dx[it]][k + dy[it]] != 'D' && grid[j + dx[it]][k + dy[it]] != 'M' && grid[j + dx[it]][k + dy[it]] != 'T') change.push_back({j + dx[it], k + dy[it]});
                        }
                    }
                }
            }
            for(auto &x : change) grid[x.first][x.second] = 'H';
            considered[q.front().second] = true;
            continue;
        }
        int x = q.front().first.first, y = q.front().first.second;
        int cur_second = q.front().second;
        q.pop();
        if(grid[x][y] == 'H' || grid[x][y] == 'T') continue;
        if(grid[x][y] == 'D') return true;
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < N && y + dy[i] < N && dist[x][y] + 1 < dist[x + dx[i]][y + dy[i]]) {
                q.push({make_pair(x + dx[i], y + dy[i]), cur_second + 1});
                dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
            }
        }
    }
    return false;
}

int bin_search() {
    int lo = 0, hi = N * N;
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
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
            store_grid[i][j] = grid[i][j];
            if(grid[i][j] == 'M') {
                start.first = i, start.second = j;
            }else if(grid[i][j] == 'D') {
                finish.first = i, finish.second = j;
            }
       }
    }
    int ans = bin_search();
    if(ans == 0) {
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


