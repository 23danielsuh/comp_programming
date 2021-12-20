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
	set<int> F;
	for(int i = 0; i < M; i++) {
		int x; cin >> x;
		F.insert(x);
	}
	vector<pi> ranges;
	sort(fields.begin(), fields.end());
	for(int i = 0; i < K; i++) {
		int pos = fields[i].first, taste = fields[i].second;
		pi cur;
		
		//calculate distL and distR
		auto L = F.lower_bound(pos);
		auto R = F.lower_bound(pos);
		int distL = INT_MAX, distR = INT_MAX;
		if(L != F.begin()) {
			L--;
			distL = abs(pos - *L);
		}
		if(R != F.end()) {
			distR = abs(pos - *R);
		}
		if(distL == INT_MAX && distR == INT_MAX) {
			assert(false);
		}

		cur.range = make_pair(pos - min(distL, distR), pos + min(distL, distR));
		cur.sum = taste;
		
		ranges.push_back(cur);
	}
	set<int> coord_comp_vals;
	map<int, int> cc;
	for(auto &x : ranges) {
		coord_comp_vals.insert(x.range.first);
		coord_comp_vals.insert(x.range.second);
	}
	int idx = 0;
	for(auto &x : coord_comp_vals) {
		idx++;
		cc[x] = idx;
	}
	cout << "\n";
	vector<int> diff(1e6 + 9, 0);
	vector<int> psum(1e6 + 9, 0);
	map<int, vector<int>> affected;
	for(auto &x : ranges) {
		x.range.first = cc[x.range.first];
		x.range.second = cc[x.range.second];
		cout << x.range.first << " " << x.range.second << " " << x.sum << "\n";
		diff[x.range.first] += x.sum;
		diff[x.range.second] -= x.sum;
		for(int i = x.range.first; i < x.range.second; i++) {
			affected[i].push_back(-x.sum);
		}
	}
	for(int i = 1; i <= 1e6 + 5; i++) {
		diff[i] += diff[i - 1];
		psum[i] += diff[i];
	}
	for(int i = 1; i <= 11; i++) {
		cout << "VALUE OF: " << psum[i] << "\n";
	}
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
}

