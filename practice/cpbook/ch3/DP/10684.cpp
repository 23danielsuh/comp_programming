#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

void solve() {
    vector<int> A(N); for(auto &x : A) cin >> x;
    int cur_sum = 0, ans = 0;
    for(int i = 0; i < N; i++) {
        cur_sum += A[i];
        if(cur_sum < 0) cur_sum = 0;
        ans = max(cur_sum, ans);
    }
    if(!ans) {
        cout << "Losing streak.\n";
    }else {
        cout << "The maximum winning streak is " << ans << ".\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        cin >> N;
        if(N == 0) break;
        solve();
    }
}