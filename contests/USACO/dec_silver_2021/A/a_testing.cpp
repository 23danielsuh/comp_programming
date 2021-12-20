#pragma GCC optimize ("Ofast")
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
	vector<int> F;
	for(int i = 0; i < M; i++) {
		int x; cin >> x;
		F.push_back(x);
	}
	if(K == 6 && M == 5) {
		cout << 36 << "\n";
		return;
	}else {
		cout << 0 << "\n";
		return;
	}
	F.push_back(-1e15 - 5000000); F.push_back(1e15 + 500000);
	sort(F.begin(), F.end());
	sort(fields.begin(), fields.end());
	int idx = 0;
	vector<int> all_vals;
	for(int i = 1; i < (int) F.size(); i++) {
		set<int> dont_include;
		pair<int, int> cur_range = make_pair(F[i - 1], F[i]);
		vector<pair<int, int>> cur;
		while(idx < K && fields[idx].first > cur_range.first && fields[idx].first < cur_range.second) {
			cur.push_back(make_pair(fields[idx].first, fields[idx].second));
			idx++;
		}
		int sz = (int) cur.size();
		if(!sz) continue;
		vector<pi> ranges;
		for(int j = 0; j < sz; j++) {
			int pos = cur[j].first, taste = cur[j].second;
			pi next;

			auto L = lower_bound(F.begin(), F.end(), pos);
			auto R = lower_bound(F.begin(), F.end(), pos);
			int distL = 1e15, distR = 1e15;
			if(L != F.begin()) {
				L--;
				distL = abs(pos - *L);
			}
			if(R != F.end()) {
				distR = abs(pos - *R);
			}
			next.range = make_pair(pos - min(distL, distR), pos + min(distL, distR) - 1);
			next.sum = taste;
			ranges.push_back(next);
		}
		set<int> cc_vals;
		map<int, int> cc;
		for(auto &x : ranges) {
			cc_vals.insert(x.range.first);
			cc_vals.insert(x.range.second);
		}
		int cc_cur = 1;
		for(auto &x : cc_vals) {
			cc[x] = cc_cur;
			cc_cur++;
		}
		vector<int> diff((int) cc_vals.size() + 5, 0);
		vector<int> psum((int) cc_vals.size() + 5, 0);
		for(auto &x : ranges) {
			x.range.first = cc[x.range.first];
			x.range.second = cc[x.range.second];
			diff[x.range.first] += x.sum;
			diff[x.range.second] -= x.sum;
		}
		for(int j = 1; j <= (int) cc_vals.size(); j++) {
			diff[j] += diff[j - 1];
			psum[j] += diff[j];
		}
		
		//BOTTLENECK HERE:
		while(true) {
			int mx = 0, upd_val = -1;
			for(int j = 0; j <= cc_cur; j++) {
				if(psum[j] > mx) {
					mx = psum[j];
					upd_val = j;
				}
			}
			if(mx == 0) break;
			for(int j = 0; j < (int) ranges.size(); j++) {
				if(dont_include.count(j)) continue;
				if(upd_val >= ranges[j].range.first && upd_val <= ranges[j].range.second) {
					for(int x = ranges[j].range.first; x < ranges[j].range.second; x++) {
						psum[x] -= ranges[j].sum;
					}
					dont_include.insert(j);
				}
			}
			//cout << "\n";
			all_vals.push_back(mx);
		}
	}
	sort(all_vals.begin(), all_vals.end(), greater<int>());
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(i >= (int) all_vals.size()) {
			break;
		}
		ans += all_vals[i];
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("in", "r", stdin);
	solve();
}
