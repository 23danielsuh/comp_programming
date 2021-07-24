#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 55;
int dp[mxN][mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    int N, M; cin >> N >> M;
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i - 2 >= 0 && j - 1 >= 0) dp[i][j] += dp[i - 2][j - 1];
            if(i - 1 >= 0 && j - 2 >= 0) dp[i][j] += dp[i - 1][j - 2];
        }
    }
    cout << dp[N - 1][M - 1] << "\n";
}

