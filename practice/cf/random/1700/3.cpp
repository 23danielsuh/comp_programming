#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    vector<int> odd_psum(N + 1), even_psum(N + 1);
    for(int i = 0; i < N; i++) {
        if(S[i] == '+') {
            odd_psum[i + 1] = pow(-1, i + 1) + odd_psum[i];
        }else {
            odd_psum[i + 1] = pow(-1, i + 1) * -1 + odd_psum[i];
        }
    }
    for(int i = 0; i < N; i++) {
        if(S[i] == '+') {
            even_psum[i + 1] = pow(-1, i) + even_psum[i];
        }else {
            even_psum[i + 1] = pow(-1, i) * -1 + even_psum[i];
        }
    }
    while(Q--) {
        int l, r; cin >> l >> r;
        int sum = 0;
        if(l % 2 == 0) {
            sum = abs(even_psum[r] - even_psum[l - 1]);
        }else {
            sum = abs(odd_psum[r] - odd_psum[l - 1]);
        }
        if(sum == 0) {
            cout << sum << "\n";
        }else {
            if((r - l + 1) & 1) {
                cout << 1 << "\n";
            }else {
                cout << 2 << "\n";
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

