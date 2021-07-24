#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 105;
int dp[mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    int N; cin >> N;
    vector<int> A(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for(auto &x : dp) x = INT_MIN;
    dp[0] = 0;
    for(int i = 0; i <= N; i++) {
        for(int step_size = 1; step_size <= 2; step_size++) {
            if(i + step_size <= N) {
                dp[i + step_size] = max(dp[i + step_size], dp[i] + A[i + step_size]);
            }
        }
    }
    cout << dp[N] << "\n";
}

