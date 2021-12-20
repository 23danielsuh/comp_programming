#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    map<string, int> mp;
    for(int i = 0; i < N; i++) {
        string x; cin >> x;
        mp[x]++;
    }
    int mx = 0; string ans = "";
    for(auto &x : mp) {
        if(x.second > mx) {
            ans = x.first;
            mx = x.second;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

