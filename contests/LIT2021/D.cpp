#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int ans = 1;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            if(i == 0) {
                if(A[i + 1] == 0) {
                    ans *= M;
                    ans %= MOD;
                    continue;
                }
                ans += (M - 1);
                ans %= MOD;
            }else if(i == N - 1) {
                if(A[i - 1] == 0 && A[i + 1] == 0) {
                    ans *= M - 1;
                    ans %= MOD;
                    continue;
                }
            }else {
                if(A[i - 1] == 0) {
                    ans *= M - 1;
                    ans %= MOD;
                    continue;
                }
                ans += (M - 1);
                ans %= MOD;
            }
        }
    }
    cout << ans << "\n";
}

