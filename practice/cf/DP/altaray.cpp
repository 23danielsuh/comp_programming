#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int dp[N];
    int prev = A[N - 1];
    for(int i = N - 1; i >= 0; i--) {
        if((prev > 0 && A[i] > 0) || (prev < 0 && A[i] < 0)) {
            dp[i] = 0;
        }else {
            dp[i] = dp[i + 1] + 1;
        }
        prev = A[i];
    }
    for(auto &x : dp) cout << x + 1 << " ";
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}