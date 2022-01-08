#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	vector<vector<int>> dirty;
	for(int i = 0; i < N; i++) {
		vector<int> temp(1, INT_MAX);
		dirty.push_back(temp);
	}
	int taken = 0;
	for(int i = 0; i < N; i++) {
		if(A[i] < taken) {
			cout << i << "\n";
			return;
		}
		//you want to place plate A[i] on the stack to the furthest left such that the condition A[i] < top is met
		int lo = 0, hi = N - 1;
		while(lo < hi) {
			int mid = (lo + hi) / 2;
			int cur = INT_MAX;
			if(dirty[mid].size() > 1) {
				cur = dirty[mid][1];
			}
			if(A[i] < cur) {
				hi = mid;
			}else {
				lo = mid + 1;
			}
		}
		while(dirty[lo].size() && dirty[lo].back() < A[i]) {
			taken = max(taken, dirty[lo].back());
			dirty[lo].pop_back();
		}
		dirty[lo].push_back(A[i]);
	}
	cout << N << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

