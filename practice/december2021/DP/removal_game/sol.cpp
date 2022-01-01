#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 5005;
using pi = pair<ll, ll>;
vector<vector<pi>> dp(mxN, vector<pi>(mxN, {0, 0}));
int N;
vector<ll> A;

void solve() {
	cin >> N;
	A.resize(N + 1);
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		dp[i][i] = {A[i], 0};
	}
	for(int i = 1; i < N; i++) {
		for(int l = 1; l + i <= N; l++) {
			int r = l + i;
			if(A[l] + dp[l + 1][r].second >= A[r] + dp[l][r - 1].second) {
				dp[l][r] = {A[l] + dp[l + 1][r].second, dp[l + 1][r].first};
			}else {
				dp[l][r] = {A[r] + dp[l][r - 1].second, dp[l][r - 1].first};
			}
		}
	}
	cout << dp[1][N].first << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

