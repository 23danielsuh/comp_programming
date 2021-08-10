#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S; cin >> S;
    string ans = "";
    map<char, char> moves;
    moves['R'] = 'S';
    moves['B'] = 'K';
    moves['L'] = 'H';
    int N = (int) S.size();
    for(int i = 0; i < N; i++) {
        set<int> cur;
        for(int j = i; j < N && j < i + 3; j++) {
            cur.insert(S[j]);
        }
        if((int) cur.size() == 3) {
            ans += 'C';
            i += 2;
            continue;
        }
        ans += moves[S[i]];
    }
    //reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

