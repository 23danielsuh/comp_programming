#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 505;
int dp[mxN][mxN];

void solve() {
	int A, B; cin >> A >> B;
	//recurrence for dp:
	//dp[i][j] = min(dp[{1...(i-1)}][j] + 1, dp[i][{1...(j-1)}] + 1)
	//
	//base case:
	//dp[i][i] = 0
	memset(dp, 0, sizeof dp);
	//for(int i = 1; i <= A; i++) {
		//dp[i][i] = 0;
	//}
	for(int i = 1; i <= A; i++) {
		for(int j = 1; j <= B; j++) {
			if(i == j) continue;
			int mn = INT_MAX;
			for(int k = 1; k < i; k++) {
				mn = min(dp[k][j] + dp[i - k][j], mn);
			}
			for(int k = 1; k < j; k++) {
				mn = min(dp[i][k] + dp[i][j - k], mn);
			}
			dp[i][j] = mn + 1;
		}
	}
	cout << dp[A][B] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

