#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

void solve() {
	int N; cin >> N;
	vector<int> A(N); 
	multiset<int> st;
	vector<int> vis(N + 5, 0);
	for(auto &x : A) {
		cin >> x;
		vis[x]++;
	}
	int mex = 0, cnt = 0;
	for(int i = 0; i <= N; i++) {
		if(!vis[i]) {
			mex = i;
			break;
		}
	}
	vector<int> ans;
	for(int i = 0; i <= N; i++) {
		if(mex > i) {
			ans.push_back(vis[i]);
			cnt++;
		}
	}
	for(int i = 0; i < N; i++) {
		if(A[i] < mex && vis[A[i]] > 1) {
			vis[A[i]]--;
			st.insert(A[i]);
		}
		if(A[i] >= mex) {
			st.insert(A[i]);
		}
	}
	vector<int> alt_ans;
	vector<int> adds;
	alt_ans.push_back(0);
	adds.push_back(0);
	bool flag = 0;
	for(int i = mex + 1; i <= N; i++) {
		auto it = st.upper_bound(i - 1);
		if(it == st.begin() || flag) {
			flag = 1;
			alt_ans.push_back(-1);
			adds.push_back(0);
			continue;
		}
		--it;
		alt_ans.push_back(*alt_ans.rbegin() + i - *it - 1);
		adds.push_back(vis[i]);
		st.erase(it);
	}
	for(auto &x : ans) cout << x << " ";
	for(int i = 0; i < (int) alt_ans.size(); i++) {
		cout << alt_ans[i] + adds[i] << " ";
	}
	cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

