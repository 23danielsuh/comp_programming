#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int X, Y, K, M; 
int dist[105][105];

int bfs() {
    queue<pair<int, int>> q;
    int ans = INT_MAX;
    q.push(make_pair(0, 0));
    dist[0][0] = 0;
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vector<pair<int, int>> next;
        ans = min(ans, abs(M - (cur.first + cur.second)));
        //state 1
        next.push_back(make_pair(X, cur.second));
        next.push_back(make_pair(cur.first, Y));

        //state 2
        next.push_back(make_pair(cur.first, 0));
        next.push_back(make_pair(0, cur.second));

        //state 3
        if(cur.first + cur.second > X) {
            next.push_back(make_pair(X, cur.second - (X - cur.first)));
        }else {
            next.push_back(make_pair(cur.first + cur.second, 0));
        }
        if(cur.first + cur.second > Y) {
            next.push_back(make_pair(cur.first - (Y - cur.second), Y));
        }else {
            next.push_back(make_pair(0, cur.first + cur.second));
        }
        for(auto &x : next) {
            if(dist[x.first][x.second] != INT_MAX || dist[cur.first][cur.second] + 1 > K) continue;
            dist[x.first][x.second] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(x.first, x.second));
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> X >> Y >> K >> M;
    for(int i = 0; i < 105; i++) for(int j = 0; j < 105; j++) dist[i][j] = INT_MAX;
    cout << bfs();
}

