#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 9;
ll dp[mxN][mxN], board[mxN][mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    for(auto &x : dp) for(auto &y : x) y = INT_MAX;
    dp[7][0] = 0;
    for(int i = 7; i >= 0; i--) {
        for(int j = 0; j < 8; j++) {
            if(i - 1 >= 0 && j + 1 < 8) dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + board[i - 1][j + 1]);
            if(i - 1 >= 0) dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + board[i - 1][j]);
            if(j + 1 < 8) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + board[i][j + 1]);
        }
    }
    cout << dp[0][7] << "\n";
}

