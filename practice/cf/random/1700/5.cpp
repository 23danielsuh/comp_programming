#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N, M; cin >> N >> M;
    vector<string> A(N); for(auto &x : A) cin >> x;
    vector<vector<int>> psum0(N + 1), psum1(N + 1);
    for(auto &x : psum0) x.resize(M + 1);
    for(auto &x : psum1) x.resize(M + 1);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            psum0[i][j] = psum0[i - 1][j] + psum0[i][j - 1] - psum0[i - 1][j - 1] + (int) (A[i][j] == 0);
            psum1[i][j] = psum1[i - 1][j] + psum1[i][j - 1] - psum1[i - 1][j - 1] + (int) (A[i][j] == 1);
        }
    }
    for(int t = 0; t < N; t++) {
        for(int b = t + 4; b < N; b++) {
            vector<int> r_psum(M + 1);
            for(int r = 0; r < M; r++) {
                //i hate this problem
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

