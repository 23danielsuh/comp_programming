#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 105;
char grid[mxN][mxN];
int N, M;

bool check(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    while(true) {
        memset(grid, 0, sizeof grid);
        cin >> N >> M;
        if(!N && !M) break;
        else if(tc != 1) cout << "\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }
        cout << "Field #" << tc << ":";
        cout << "\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] == '*') {
                    cout << grid[i][j];
                }else {
                    int sum = 0;
                    if(check(i - 1, j) && grid[i - 1][j] == '*') sum++;
                    if(check(i + 1, j) && grid[i + 1][j] == '*') sum++;
                    if(check(i - 1, j + 1) && grid[i - 1][j + 1] == '*') sum++;
                    if(check(i - 1, j - 1) && grid[i - 1][j - 1] == '*') sum++;
                    if(check(i + 1, j + 1) && grid[i + 1][j + 1] == '*') sum++;
                    if(check(i + 1, j - 1) && grid[i + 1][j - 1] == '*') sum++;
                    if(check(i, j + 1) && grid[i][j + 1] == '*') sum++;
                    if(check(i, j - 1) && grid[i][j - 1] == '*') sum++;
                    cout << sum;
                }
            }
            cout << "\n";
        }
        tc++;
    }
}

