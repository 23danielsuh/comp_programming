#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

const int mxN = 3e5 + 5;
int dp[mxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    vector<int> stacks(200);
    stacks[0] = 1;
    for(int i = 1; i < 200; i++) {
        stacks[i] = (i + 1) * i / 2 + stacks[i - 1] + i + 1;
    }
    dp[0] = 0;
    for(int i = 1; i < mxN; i++) {
        dp[i] = numeric_limits<ll>::max();
        for(auto &x : stacks) {
            if(i - x >= 0) {
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
    }
    while(T--) {
        int N; cin >> N;
        cout << dp[N] << "\n";
    }
}

