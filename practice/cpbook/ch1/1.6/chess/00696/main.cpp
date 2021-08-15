#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int N, M; cin >> N >> M;
        if(!N && !M) break;
        int ans = 0;
        if(N == 1) ans = M;
        else if(M == 1) ans = N;
        else if(N == 2 || M == 2) {
            ans = fdiv(max(N, M), 4) * 4;
            if(max(N, M) % 4 == 1) {
                ans += 2;
            }else if(max(N, M) % 4 > 1) {
                ans += 4;
            }
        }
        else ans = cdiv(M, 2) * cdiv(N, 2) + fdiv(M, 2) * fdiv(N, 2);
        cout << ans << " knights may be placed on a " << N << " row " << M << " column board.\n";
    }
}

