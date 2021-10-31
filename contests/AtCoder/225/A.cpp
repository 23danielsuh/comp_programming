#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string S; cin >> S;
    sort(S.begin(), S.end());
    set<string> ans;
    do {
        ans.insert(S);
    }while(next_permutation(S.begin(), S.end()));
    cout << ans.size() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}