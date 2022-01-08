#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N); for(auto &x : A) cin >> x;
	vector<int> cnt(1e6 + 5, 0);
	multiset<int> sw;
	int r = 0, cnt_num = 0;
	pair<int, int> ans;
	for(int l = 0; l < N; l++) {
		while(r < N && cnt_num + (cnt[A[r]] == 0) <= K) {
			cnt_num += (cnt[A[r]] == 0);
			sw.insert(A[r]);
			cnt[A[r]]++;
			r++;
		}
		
		sw.erase(sw.find(A[l]));
		cnt[A[l]]--;
		cnt_num -= (cnt[A[l]] == 0);
		if(r - l > ans.second - ans.first) {
			ans = {l, r};
		}
	}
	cout << ans.first + 1 << " " << ans.second << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

