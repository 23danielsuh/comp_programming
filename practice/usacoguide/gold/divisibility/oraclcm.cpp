#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    vector<int> suf_gcd(N + 1); 
    suf_gcd[N] = A[N - 1];
    for(int i = N; i > 0; i--) {
        suf_gcd[i - 1] = gcd(suf_gcd[i], A[i - 1]);
    }
    int ans = -1;
    for(int i = 0; i < N - 1; i++) {
        int a = A[i], b = suf_gcd[i + 1];
        if(ans == -1) {
            ans = a * b / gcd(a, b);
        }else {
            ans = gcd(ans, a * b / gcd(a, b));
        }
    }
    cout << ans << "\n";
}
