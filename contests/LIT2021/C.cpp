#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct P {
    int x, y;
};

const int mxN = 55;
char grid1[mxN][mxN], grid2[mxN][mxN];
int N, M;
P alicia_start, kevin_start, alicia_end, kevin_end;

void output() {
    cout << "\n";
    grid1[alicia_start.x][alicia_start.y] = 'A';
    grid1[alicia_end.x][alicia_end.y] = 'E';
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << grid1[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    grid2[kevin_start.x][kevin_start.y] = 'K';
    grid2[kevin_end.x][kevin_end.y] = 'E';
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << grid2[i][j];
        }
        cout << "\n";
    }
}

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int visited[mxN][mxN][mxN][mxN];

queue<pair<P, P>> q; 

void check(P a_next, P a, P k_next, P k) {
    bool a_out = (a_next.x <= 0 || a_next.x > N || a_next.y <= 0 || a_next.y > M);
    bool k_out = (k_next.x <= 0 || k_next.x > N || k_next.x <= 0 || k_next.y > M);
    if(a_out && k_out) return;
    if(a_out) {
        if(grid2[k_next.x][k_next.y] == '#') return;
    }
    if(k_out) {
        if(grid1[a_next.x][a_next.y] == '#') return;
    }
    if(grid1[a_next.x][a_next.y] == '#' && grid2[k_next.x][k_next.y] == '#') return;
    if(grid1[a_next.x][a_next.y] == '#' || a_out) {
        if(visited[a.x][a.y][k.x][k.y] + 1 < visited[a.x][a.y][k_next.x][k_next.y]) {
            q.push(make_pair(a, k_next));
            visited[a.x][a.y][k_next.x][k_next.y] = visited[a.x][a.y][k.x][k.y] + 1;
        }
        return;
    }
    if(grid2[k_next.x][k_next.y] == '#' || k_out) {
        if(visited[a.x][a.y][k.x][k.y] + 1 < visited[a_next.x][a_next.y][k.x][k.y]) {
            q.push(make_pair(a_next, k));
            visited[a_next.x][a_next.y][k.x][k.y] = visited[a.x][a.y][k.x][k.y] + 1;
        }
        return;
    }
    if(grid2[k_next.x][k_next.y] != '#' && grid1[a_next.x][a_next.y] != '#' && !a_out && !k_out) {
        if(visited[a.x][a.y][k.x][k.y] + 1 < visited[a_next.x][a_next.y][k_next.x][k_next.y]) {
            q.push(make_pair(a_next, k_next));
            visited[a_next.x][a_next.y][k_next.x][k_next.y] = visited[a.x][a.y][k.x][k.y] + 1;
        }
        return;
    }
}

int ans = INT_MAX;

void BFS() {
    q.push(make_pair(alicia_start, kevin_start));
    for(int i = 0; i < mxN; i++)
        for(int j = 0; j < mxN; j++)
            for(int k = 0; k < mxN; k++)
                for(int x = 0; x < mxN; x++) 
                    visited[i][j][k][x] = INT_MAX;

    visited[alicia_start.x][alicia_start.y][kevin_start.x][kevin_start.y] = 0;
    while(!q.empty()) {
        P alicia = q.front().first; 
        P kevin = q.front().second; q.pop();
        if(alicia.x <= 0 || alicia.x > N || alicia.y <= 0 || alicia.y > M || kevin.x <= 0 || kevin.x > N || kevin.y <= 0 || kevin.y > M) { continue; }
        if(alicia.x == alicia_end.x && alicia.y == alicia_end.y && kevin.x == kevin_end.x && kevin.y == kevin_end.y) {
            ans = min(ans, visited[alicia.x][alicia.y][kevin.x][kevin.y]);
        }
        for(int i = 0; i < 4; i++) {
            P alicia_next = alicia, kevin_next = kevin;
            alicia_next.x += dx[i];
            alicia_next.y += dy[i];
            kevin_next.x += dx[i];
            kevin_next.y += dy[i];
            check(alicia_next, alicia, kevin_next, kevin);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    cin >> alicia_start.x >> alicia_start.y >> kevin_start.x >> kevin_start.y;
    cin >> alicia_end.x >> alicia_end.y >> kevin_end.x >> kevin_end.y;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> grid1[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> grid2[i][j];
        }
    }
    //output();
    BFS();
    if(ans == INT_MAX) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans;
}

