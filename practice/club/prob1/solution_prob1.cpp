#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int mn = INT_MAX, index = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < mn) {
            mn = A[i];
            index = i;
        }
    }
    cout << index + 1 << " ";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}