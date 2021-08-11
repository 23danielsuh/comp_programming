#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc = 1; cin >> T;
    while(T--) {
        string a, b; cin >> a >> b;
        int N = (int) a.size();
        int diff = 0, zero_one = 0, one_zero = 0, cnt = 0;
        for(int i = 0; i < N; i++) {
            if(a[i] != b[i]) {
                diff++;
            }
            if(a[i] == '1' && b[i] == '0') {
                zero_one++;
            }else if(a[i] == '0' && b[i] == '1') {
                one_zero++;
            }
            if(a[i] == '1') {
                cnt--;
            }
            if(b[i] == '1') {
                cnt++;
            }
        }
        cout << "Case " << tc << ": " << (cnt < 0 ? -1 : diff - min(zero_one, one_zero)) << "\n";
        tc++;
    }
}
