#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<int> A(N); int mx = INT_MIN; for(auto &x : A) cin >> x;
        for(auto &x : A) mx = max(mx, x);
        bool flag = 0;
        double sum = 0;
        for(int i = 0; i < N; i++) {
            if(!flag && A[i] == mx) {
                flag = 1;
                continue;
            }
            sum += A[i];
        }
        cout << fixed << setprecision(8);
        cout << double(sum) / double(N - 1) + double(mx) << "\n";
    }
}

