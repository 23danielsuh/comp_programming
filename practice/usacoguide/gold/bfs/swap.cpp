#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool check(int x) {
    return x >= 0 && x < 3;
}

void solve() {
    vector<int> hash_values(9);
    map<vector<vector<int>>, bool> vis;
    vector<vector<int>> A(3);
    A[0].resize(3);
    A[1].resize(3);
    A[2].resize(3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    queue<pair<vector<vector<int>>, int>> q;
    vis[A] = true;
    q.push({A, 0});
    while(!q.empty()) {
        vector<vector<int>> cur = q.front().first; int dist = q.front().second; q.pop();
        bool flag = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(cur[i][j] != i * 3 + j + 1) {
                    flag = 1;
                }
            }
        }
        if(!flag) {
            cout << dist << "\n";
            return;
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 4; k++) {
                    vector<vector<int>> temp = cur;
                    if(check(i + dx[k]) && check(j + dy[k])) {
                        swap(temp[i][j], temp[i + dx[k]][j + dy[k]]);
                        if(!vis[temp]) {
                            q.push({temp, dist + 1});
                        }
                    }
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}