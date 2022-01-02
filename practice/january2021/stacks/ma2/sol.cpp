#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
	stack<int> st;
	vector<bool> visited(1e5 + 5, 0); vector<int> cnt(1e5 + 5, 0);
	int mx = 0;
	for(int i = 0; i < N; i++) {
		int runs = 0;
		while(!st.empty() && visited[A[i]] && st.top() != A[i]) {
			cnt[A[i]] += max(1, cnt[st.top()]);
			st.pop();
			runs++;
		}
		//if(!st.empty() && visited[A[i]]) {
			//st.pop();
		//}
		visited[A[i]] = true;
		st.push(A[i]);
		stack<int> cpy = st;
		while(!cpy.empty()) {
			//cout << cpy.top() << " ";
			cpy.pop();
		}
		//cout << "\n";
		mx = max(runs, mx);
	}
	cout << *max_element(cnt.begin(), cnt.end());
	//for(int i = 0; i <= 10; i++) {
		//cout << i << ": " << cnt[i] << "\n";
	//}
	//cout << mx << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
    int T = 1;
    //cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

