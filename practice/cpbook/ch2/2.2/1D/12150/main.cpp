#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int N; cin >> N;
        if(!N) break;
        vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
        vector<int> ans(N, -1);
        bool flag = 0;
        for(int i = 0; i < N; i++) {
            if(i + A[i].second < 0 || i + A[i].second >= N) {
                flag = 1;
                break;
            }
            if(ans[i + A[i].second] != -1) {
                flag = 1;
                break;
            }
            ans[i + A[i].second] = A[i].first;
        }
        if(flag) {
            cout << -1 << "\n";
            continue;
        }
        for(int i = 0; i < N; i++) {
            cout << ans[i];
            if(i != N - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

