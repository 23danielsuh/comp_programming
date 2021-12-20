#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

struct pi {
	pair<int, int> range;
	int sum = 0;
};

void solve() {
	int K, M, N; cin >> K >> M >> N;
	vector<pair<int, int>> fields(K); for(auto &x : fields) cin >> x.first >> x.second;
	vector<int> F(M); for(auto &x : F) cin >> x;
	for(auto &x : fields) x.first *= 2;
	for(auto &x : F) x *= 2;
	F.push_back(-1e12); F.push_back(1e12);
	sort(fields.begin(), fields.end());
	sort(F.begin(), F.end());
	int idx = 0;
	vector<int> ans;
	for(int i = 1; i < (int) F.size(); i++) {
		pair<int, int> cur_range = make_pair(F[i - 1], F[i]);
		vector<pair<int, int>> inv;
		while(idx < K && fields[idx].first > cur_range.first && fields[idx].first < cur_range.second) {
			inv.push_back(make_pair(fields[idx].first, fields[idx].second));
			idx++;
		}
		//investigate inv with two pointers, hmm...
		int sz = (int) inv.size();
		if(!sz) continue;
		int r = 0, sum_now = 0;
		vector<pi> ranges;
		//the open circles for this array are at F[i - 1] and F[i]
		for(int l = 0; l < sz; l++) {
			if(l > 0) sum_now -= inv[l - 1].second;
			r = max(l, r);
			int med = (inv[l].first + inv[r].first) / 2;
			while(r < sz && abs(inv[l].first - med) < abs(inv[l].first - F[i - 1]) && abs(inv[r].first - med) < abs(inv[l].first - F[i])) {
				sum_now += inv[r].second;
				r++;
				if(r < sz) {
					med = (inv[l].first + inv[r].first) / 2;
				}else {
					break;
				}
			}
			pi cur;
			cur.range = make_pair(l, r - 1);
			cur.sum = sum_now;
			ranges.push_back(cur);
		}
		int mx = 0;
		for(auto &x : ranges) {
			mx = max(x.sum, mx);
		}
		ans.push_back(mx);
	}
	sort(ans.begin(), ans.end(), greater<int>());
	int sum = 0;
	for(int i = 0; i < N; i++) {
		if(i >= (int) ans.size()) break;
		sum += ans[i];
	}
	cout << sum << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
}

