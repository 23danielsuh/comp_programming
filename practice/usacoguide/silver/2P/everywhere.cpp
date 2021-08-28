#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    set<char> has;
    for(char c : S) has.insert(c);
    int cnt = (int) has.size();
    int l = 0, r = 0;
    map<char, int> mp;
    int ans = INT_MAX;
    while(l < N && r < N) {
        if(mp.size() != cnt) {
            mp[S[r]]++;
            r++;
        }
        while(mp.size() == cnt) {
            mp[S[l]]--;
            if(mp[S[l]] == 0) {
                mp.erase(S[l]);
            }
            l++;
            ans = min(ans, r - l + 1);
        }
    }
    cout << ans << "\n";
}

