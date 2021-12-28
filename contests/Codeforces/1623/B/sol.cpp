#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second - a.first < b.second - b.first;
}

void solve() {
	int N; cin >> N;
	vector<pair<int, int>> A(N); for(auto &x : A) cin >> x.first >> x.second;
	sort(A.begin(), A.end(), cmp);
	map<int, bool> blacklist;
	map<int, bool> considered;
	vector<array<int, 3>> ans;
	for(int i = 0; i < N; i++) {
		if(A[i].second - A[i].first == 0) {
			considered[A[i].first] = true;
			blacklist[i] = true;
			ans.push_back({A[i].first, A[i].second, A[i].first});
		}
	}
	for(int i = 1; i <= N; i++) {
		if(considered[i]) continue;
		int mn = INT_MAX; int idx = -1;
		for(int j = 0; j < N; j++) {
			if(i >= A[j].first && i <= A[j].second && !blacklist[j]) {
				if(A[j].second - A[j].first < mn) {
					mn = A[j].second - A[j].first;
					idx = j;
				}
			}
		}
		blacklist[idx] = true;
		ans.push_back({A[idx].first, A[idx].second, i});
	}
	for(auto &x : ans) {
		for(auto &y : x) cout << y << " ";
		cout << "\n";
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

