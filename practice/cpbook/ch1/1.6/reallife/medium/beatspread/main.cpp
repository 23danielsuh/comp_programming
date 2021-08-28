#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int s, d; cin >> s >> d;
        pair<int, int> ans = make_pair(INT_MAX, INT_MAX);
        for(int i = 0; i <= 1000; i++) {
            for(int j = 0; j <= 1000; j++) {
                if(abs(i - j) == d && i + j == s) {
                    ans = make_pair(i, j);
                }
            }
        }
        if(ans == make_pair(INT_MAX, INT_MAX)) { cout << "impossible\n"; continue;}
        cout << ans.first << " " << ans.second << "\n";
    }
}

