#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

vector<int> compute(vector<int> A, int N) {
	stack<pair<int, int>> st;
	int cur = 0, acc = 0;
	vector<int> ret(N);
	for(int i = 0; i < N; i++) {
		while(st.size() && A[i] < st.top().first) {
			acc -= st.top().second;
			cur += st.top().first;
			st.pop();
		}
		cur += A[i];
		ret[i] = cur;
		st.push({A[i], i});
	}
	return ret;
}

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	stack<pair<int, int>> st;
	vector<int> forward = compute(A, N);
	reverse(A.begin(), A.end());
	for(auto &x : forward) cout << x << " ";
	cout << "\n";
	vector<int> backward = compute(A, N);
	reverse(backward.begin(), backward.end());
	for(auto &x : backward) cout << x << " ";
	cout << "\n";
	int mx = 0;
	int idx = 0;
	reverse(A.begin(), A.end());
	for(int i = 0; i < N; i++) {
		cout << forward[i] + backward[i] - A[i] << "\n";
		if(forward[i] + backward[i] - A[i] > mx) {
			mx = max(mx, forward[i] + backward[i] - A[i]);
			idx = i;
		}
	}
	vector<int> ans(N);
	ans[idx] = A[idx];
	for(int i = idx - 1; i >= 0; i--) {
		ans[i] = min(ans[i + 1], A[i]);
	}
	for(int i = idx + 1; i < N; i++) {
		ans[i] = min(ans[i - 1], A[i]);
	}
	for(auto &x : ans) cout << x << " ";
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
