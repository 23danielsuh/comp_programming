#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N);
	int sum = 0;
	for(auto &x : A) {
		cin >> x;
		sum += x;
	}
	sort(A.begin(), A.end());
	stack<int> stck;
	for(int i = 1; i < N; i++) {
		stck.push(A[i] - A[0]);
	}
	int cnt = 0;
	int mn = LLONG_MAX;
	while(!stck.empty() && sum > K) {
		mn = min(mn, cnt + (sum - K + cnt) / (cnt + 1));
		cnt++;
		sum -= stck.top();
		stck.pop();
	}
	if(sum > K) {
		cnt += (sum - K + cnt) / (cnt + 1);
	}
	cout << min(mn, cnt) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

