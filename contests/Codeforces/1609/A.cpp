#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int mx = 0;
    for(int i = 0; i < N; i++) {
        vector<int> B = A;
        int mult = 1, sum = 0;
        for(int j = 0; j < N; j++) {
            if(i != j) {
                while(B[j] % 2 == 0) {
                    B[j] /= 2;
                    mult *= 2;
                }
                sum += B[j];
            }
        }
        mx = max(mx, mult * A[i] + sum);
    }
    cout << mx << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

