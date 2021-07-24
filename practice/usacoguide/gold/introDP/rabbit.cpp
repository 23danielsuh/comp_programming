#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1005;
int dp[mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    int N; cin >> N;
    vector<char> A(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for(auto &x : dp) x = INT_MIN;
    dp[1] = 0;
    for(int i = 1; i <= N; i++) {
        for(int step_size = 1; step_size <= 5; step_size += 2) {
            if(i + step_size <= N) {
                if(A[i + step_size] == 'w' || dp[i] == INT_MIN) continue;
                dp[i + step_size] = max(dp[i + step_size], dp[i] + int(A[i + step_size] == '"'));
            }
        }
    }
    if(dp[N] == INT_MIN) {
        cout << -1 << "\n";
        return 0;
    }
    cout << dp[N] << "\n";
}

