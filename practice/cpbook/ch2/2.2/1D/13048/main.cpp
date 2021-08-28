#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc = 1; cin >> T;
    while(T--) {
        string S; cin >> S;
        int N = (int) S.size();
        vector<bool> pos(N, 1);
        for(int i = 0; i < N; i++) {
            if(S[i] == 'D') {
                pos[i] = 0;
            }
            if(S[i] == 'B') {
                pos[i] = 0;
                if(i - 1 >= 0) {
                    pos[i - 1] = 0;
                }
                if(i - 2 >= 0) {
                    pos[i - 2] = 0;
                }
            }
            if(S[i] == 'S') {
                pos[i] = 0;
                if(i + 1 < N) {
                    pos[i + 1] = 0;
                }
                if(i - 1 >= 0) {
                    pos[i - 1] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            if(pos[i]) ans++;
        }
        cout << "Case " << tc << ": " << ans << "\n";
        tc++;
    }
}

