#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S; cin >> S;
    vector<bool> ans = {1, 0, 0};
    for(int i = 0; i < (int) S.size(); i++) {
        if(S[i] == 'A') {
            swap(ans[0], ans[1]);
        }else if(S[i] == 'B') {
            swap(ans[1], ans[2]);
        }else {
            swap(ans[0], ans[2]);
        }
    }
    for(int i = 0; i < 3; i++) {
        if(ans[i]) cout << i + 1 << "\n";
    }
}

