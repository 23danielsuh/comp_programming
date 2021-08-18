#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int a, b, c; cin >> a >> b >> c;
        int mx = abs(a - b) * 2, dist = abs(a - b);
        if(a > mx || b > mx || c > mx) { cout << -1 << "\n"; continue; }
        int pos;
        if(c > dist) {
            pos = c - dist;
        }else {
            pos = c + dist;
        }
        cout << pos << "\n";
    }
}

