#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N + 1);
    int mn = LLONG_MAX, idx = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        if(A[i] <= mn) {
            mn = A[i];
            idx = i;
        }
    }
    int pos2 = LLONG_MIN;
    for(int i = 1; i <= N; i++) {
        if(i != idx) {
            pos2 = max(pos2, (i * idx) - K * (A[i] | A[idx]));
        }
    }
    int pos1 = (N * (N - 1)) - K * (A[N] | A[N - 1]);
    cout << max(pos1, pos2) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

