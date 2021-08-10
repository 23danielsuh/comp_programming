#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, i, j; 
    while(cin >> N) {
        cin >> i >> j;
        int ans = INT_MAX, N_pow = pow(2, N), cur = 1, cnt = 0;
        while(cur <= N_pow) {
            if(cdiv(i, cur) == cdiv(j, cur)) {
                ans = min(ans, cnt);
            }
            cur *= 2, cnt++;
        }
        cout << ans << "\n";
    }
}

