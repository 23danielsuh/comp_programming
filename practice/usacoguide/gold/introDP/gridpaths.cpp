#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1005, MOD = 1e9 + 7;
char grid[mxN][mxN];
int dp[mxN][mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if(i - 1 >= 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if(j - 1 >= 0) {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[N - 1][N - 1] << "\n";
}

