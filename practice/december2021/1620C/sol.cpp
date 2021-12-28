#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, K; ll X; cin >> N >> K >> X;
	X--;
	string S; cin >> S;
	vector<int> lens;
	for(int i = 0; i < N; i++) {
		int len = 0;
		while(i < N && S[i] == '*') {
			i++;
			len++;
		}
		if(len) lens.push_back(len * K + 1);
	}
	reverse(lens.begin(), lens.end());
	vector<int> ans;
	for(int idx = 0; idx < (int) lens.size(); idx++) {
		ans.push_back(X % lens[idx]);
		X /= lens[idx];
	}
	int idx = 0;
	string cur;
	for(int i = N - 1; i >= 0; i--) {
		if(S[i] == 'a') {
			cur += 'a';
			continue;
		}
		while(i >= 0 && S[i] == '*') {
			i--;
		}
		i++;
		if(idx >= (int) ans.size()) continue;
		for(int j = 0; j < ans[idx]; j++) {
			cur += 'b';
		}
		idx++;
	}
	reverse(cur.begin(), cur.end());
	cout << cur << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}



