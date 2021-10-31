#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> a;
    for(int i = 0; i < N; i++) {
        a.push_back(S[i] - 'a');
    }
    cout << a.size() << "\n";
    for(auto &x : a) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}