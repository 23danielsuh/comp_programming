#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 1e7, mxNN = 1e7 + 5;
vector<bool> is_prime(mxNN, true);

void sieve() {
    for (int i = 2; i <= mxN; i++) {
        if (is_prime[i] && (long long)i * i <= mxN) {
            for (int j = i * i; j <= mxN; j += i)
                is_prime[j] = false;
        }
    }
}

void solve() {
    int N, E; cin >> N >> E;
    vector<int> A(N); for(auto &x : A) cin >> x;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(is_prime[A[i]] && A[i] != 1) {
            int l = 0, r = 0;
            for(int j = i - E; j >= 0; j -= E) {
                if(A[j] == 1) {
                    l++;
                }else {
                    break;
                }
            }
            for(int j = i + E; j < N; j += E) {
                if(A[j] == 1) {
                    r++;
                }else {
                    break;
                }
            }
            ans += l + r + l * r;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    sieve();
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

