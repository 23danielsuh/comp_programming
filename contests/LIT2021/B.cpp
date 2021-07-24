#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
    int ans = 2;
    if(N < 3) {
        cout << N << "\n";
        return 0;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int cur = 2;
            if(i == j) continue;
            int x1 = A[i].first, x2 = A[j].first, y1 = A[i].second, y2 = A[j].second;
            for(int k = 0; k < N; k++) {
                if(i == k || j == k) continue;
                int x3 = A[k].first, y3 = A[k].second;
                if((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2)) cur++;
            }
            //cout << i << " " << j << " " << cur << "\n";
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}

