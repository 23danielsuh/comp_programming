#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        vector<pair<int, int>> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i].first;
            A[i].second = i;
        }
        sort(A.begin(), A.end());
        int cnt = N;
        for(int i = 1; i < N; i++) {
            if(A[i].second - A[i - 1].second == 1) {
                cnt--;
            }
        }
        cout << (cnt <= K ? "YES\n" : "NO\n");
        //printf(cnt <= K ? "YES\n" : "NO\n");
    }
}

