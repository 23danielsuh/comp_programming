#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

vector<ll> compute(int N, vector<int> &A) {
	vector<ll> ret(N);
	stack<int> st;
	for(int i = 0; i < N; i++) {
		while(st.size() && A[i] < A[st.top()]) {
			st.pop();
		}
		ll cur = 0;
		if(st.size()) {
			cur = ret[st.top()] + (i - st.top()) * A[i];
		}else {
			cur = (i + 1) * A[i];
		}
		//ll cur = ret[st.top()];
		//cur += (i - st.top()) * A[i];
		ret[i] = cur;
		st.push(i);
	}
	return ret;
}

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	vector<int> forward = compute(N, A);
	//for(auto &x : forward) cout << x << " ";
	//cout << "\n";
	reverse(A.begin(), A.end());
	vector<int> backward = compute(N, A);
	reverse(backward.begin(), backward.end());
	//for(auto &x : backward) cout << x << " ";
	//cout << "\n\n";
	int idx = 0, mx = 0;
	reverse(A.begin(), A.end());
	for(int i = 0; i < N; i++) {
		if(backward[i] + forward[i] - A[i] > mx) {
			mx = backward[i] + forward[i] - A[i];
			idx = i;
		}
	}
	vector<int> ans(N);
	ans[idx] = A[idx];
	for(int i = idx + 1; i < N; i++) {
		ans[i] = min(ans[i - 1], A[i]);
	}
	for(int i = idx - 1; i >= 0; i--) {
		ans[i] = min(ans[i + 1], A[i]);
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

