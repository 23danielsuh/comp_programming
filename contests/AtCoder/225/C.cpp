#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N, M; cin >> N >> M;
    int grid[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    bool flag = 0;
    for(int i = 0; i < N; i++) {
        int last_element = ((grid[i][0] - 1) / 7) * 7 + 7;
        for(int j = 0; j < M - 1; j++) {
            if(grid[i][j + 1] > last_element) flag = 1;
            if(grid[i][j + 1] - grid[i][j] != 1) flag = 1;
        }
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N - 1; j++) {
            if(grid[j + 1][i] - grid[j][i] != 7) flag = 1;
        }
    }
    cout << (flag ? "No" : "Yes") << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}