#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int N; cin >> N;
    vector<int> A(N); for(auto &x : A) cin >> x;
    for(int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
    
}

/*
 * bitwise operator AND observations:
 * x & x = x
 * x & y = y & x
 * x & x & y = x & y
 * 
 * a_1 a_2 a_3
 * a_4 a_5 a_6
 * 
 * possible paths are: a_1 & a_2 & a_3 or a_1 & a_3 & a_4
 * a_5 = max((a_1 & a_4) & a_5, (a_1 & a_2) & a_5)
 * a_3 = a_1 & a_2 & a_3
 * a_6 = max(a_5, a_3)
 * 
 */
