#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1005;
char grid[mxN][mxN];
pair<int, int> from[mxN][mxN];
int dist[mxN][mxN];
bool one_it = 0, possible = 0;
int N, M;
pair<int, int> start_pos;
queue<pair<int, int>> q;

string ans(int x, int y) {
    string ret = "";
    pair<int, int> cur = make_pair(x, y);
    while(from[cur.first][cur.second].first != INT_MAX) {
        if(from[cur.first][cur.second] == make_pair(cur.first - 1, cur.second)) ret += 'D';
        if(from[cur.first][cur.second] == make_pair(cur.first + 1, cur.second)) ret += 'U';
        if(from[cur.first][cur.second] == make_pair(cur.first, cur.second + 1)) ret += 'L';
        if(from[cur.first][cur.second] == make_pair(cur.first, cur.second - 1)) ret += 'R';
        cur = from[cur.first][cur.second];
    }
    return ret;
}

void check(pair<int, int> origin, pair<int, int> dest) {
    if(dest.first < 0 || dest.first >= N || dest.second < 0 || dest.second >= M) return;
    int cur_dist = dist[origin.first][origin.second];
    if(cur_dist + 1 < dist[dest.first][dest.second]) {
        q.push(make_pair(dest.first, dest.second));
        dist[dest.first][dest.second] = cur_dist + 1;
        if(one_it) from[dest.first][dest.second] = origin;
    }
}

pair<int, int> ex;

void bfs() {
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        pair<int, int> next = cur; next.first--; check(cur, next);
        next = cur; next.first++; check(cur, next);
        next = cur; next.second--; check(cur, next);
        next = cur; next.second++; check(cur, next);
        if(one_it && (cur.first == 0 || cur.second == 0 || cur.first == N - 1 || cur.second == M - 1)) {
            possible = true;
            ex.first = cur.first, ex.second = cur.second;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'M') {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }else if(grid[i][j] == 'A') {
                start_pos = make_pair(i, j);
            }else if(grid[i][j] == '#') {
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    one_it = true;
    from[start_pos.first][start_pos.second] = make_pair(INT_MAX, INT_MAX);
    dist[start_pos.first][start_pos.second] = 0; q.push(make_pair(start_pos.first, start_pos.second));
    bfs();
    if(possible) {
        cout << "YES" << "\n";
        string re = ans(ex.first, ex.second);
        cout << re.size() << "\n";
        reverse(re.begin(), re.end());
        cout << re;
    }else {
        cout << "NO" << "\n";
    }
}
