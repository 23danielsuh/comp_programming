#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 805;
int N, S; 
char grid[mxN][mxN];

bool check(int seconds) {
    // Can you just simulate the first w seconds and then find the BFS thing?
    
}

int bin_search() {
    int lo = 0, hi = N * N;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) {
            lo = mid;
        }else {
            hi = mid - 1;
        }
    }
    return lo;
}

void solve() {
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
       }
    }
    cout << bin_search() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}


