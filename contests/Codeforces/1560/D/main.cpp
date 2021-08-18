#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    vector<string> powers;
    for(int i = 0; i < log2(numeric_limits<ll>::max()); i++) {
        powers.push_back(to_string(int(pow(2, i))));
    }
    while(T--) {
        string S; cin >> S;
        int N = (int) S.size();
        //you need to get the left side as equal as possible:
        //12956
        //26523
        //
        int ans = INT_MAX;
        for(auto &x : powers) {
            string target = x;
            int start = 0, cnt = 0;
            for(int i = 0; i < (int) target.size(); i++) {
                bool flag = 0;
                for(int j = start; j < N; j++) {
                    if(S[j] == target[i]) {
                        start = j + 1;
                        flag = 1;
                        break;
                    }
                }
                if(!flag) break;
                cnt++;
            }
            int steps = N - cnt;
            steps += (int) target.size() - cnt;
            ans = min(ans, steps);
        }
        cout << ans << "\n";
    }
}

