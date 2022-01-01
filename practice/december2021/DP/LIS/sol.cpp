#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	vector<int> dp;
	for(int i = 0; i < N; i++) {
		//optimize to log(N):
		//for(int j = 0; j < i; j++) {
			//if(A[j] < A[i]) {
				//dp[i] = max(dp[i], dp[j] + 1);
			//}
		//}
		
		int dist = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if(dist == (int) dp.size()) {
			dp.push_back(A[i]);
		}else {
			dp[dist] = A[i];
		}
	}
	cout << (int) dp.size() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

