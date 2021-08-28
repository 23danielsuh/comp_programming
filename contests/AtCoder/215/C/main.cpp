#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S; int N; cin >> S >> N;
    vector<string> ans;
    sort(S.begin(), S.end());
    do {
        ans.push_back(S);
    }while(next_permutation(S.begin(), S.end()));
    sort(ans.begin(), ans.end());
    cout << ans[N - 1] << "\n";
}

