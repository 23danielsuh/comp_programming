#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for(auto &x : A) cin >> x;
        sort(A.begin(), A.end());
        for(int i = 0; i < N; i++) {
            cout << A[i] << " " ;
        }
        cout << "\n";
    }
}

