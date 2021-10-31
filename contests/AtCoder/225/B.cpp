#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    map<int, int> cnt;
    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    for(auto &x : cnt) {
        if(x.second == N - 1) {
            cout << "Yes\n"; 
            return;
        }
    }
    cout << "No\n"; 
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}