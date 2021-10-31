#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    vector<array<int, 3>> A;
    for(int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        A.push_back({a, b, c});
    }
    int dp[N][3];
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 3; i++) {
        dp[0][i] = A[0][i];
    }
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            int first = (j + 1) % 3, second = (j + 2) % 3;
            dp[i][j] = max(dp[i][j], dp[i - 1][first] + A[i][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][second] + A[i][j]);
        }
    }
    cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}