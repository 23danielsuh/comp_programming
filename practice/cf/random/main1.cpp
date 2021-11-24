#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    for(int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

